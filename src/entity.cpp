
#include <cstring>
#include <cassert>
#include "common.h"


#define PROP_INTEGER(name) \
    static int read_##name(lua_State *L, entity_t *entity) { lua_pushinteger(L, entity->name); return 1; }; \
    static int write_##name(lua_State *L, entity_t *entity) { entity->name = lua_tointeger(L, -1); return 0; };

#define PROP_BOOLEAN(name) \
    static int read_##name(lua_State *L, entity_t *entity) { lua_pushboolean(L, entity->name); return 1; }; \
    static int write_##name(lua_State *L, entity_t *entity) { entity->name = lua_toboolean(L, -1); return 0; };

#define PROP_FLOAT(name) \
    static int read_##name(lua_State *L, entity_t *entity) { lua_pushnumber(L, entity->name); return 1; }; \
    static int write_##name(lua_State *L, entity_t *entity) { entity->name = lua_tonumber(L, -1); return 0; };

#define SETUP_PROP(name) entity_prop_info[prop_count ++] = {#name, read_##name, write_##name }



prop_info_t *entity_prop_info_hashtable[128];
prop_info_t entity_prop_info[10];
entity_t entities[MAX_ENTITY];

static unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) * 33 + c; /* hash * 33 + c */

//        printf("original hash %lu\n", hash);
    return hash & 0x7f;
}

PROP_FLOAT(x);
PROP_FLOAT(y);
PROP_INTEGER(index);
PROP_FLOAT(angle);
PROP_BOOLEAN(active);
PROP_FLOAT(drawScale);

static prop_info_t *getPropForName(const char *name) {
    long int h = hash(name);
    if(entity_prop_info_hashtable[h]) {
        if(!strcmp(name, entity_prop_info_hashtable[h]->name)) {
            return entity_prop_info_hashtable[h];
        } else {
            printf("Warning: has collided and didn't find property: %s\n", name);
        }
    }

    return NULL;
}

static int l_is_internal_prop(lua_State *L) {
    const char *prop = lua_tostring(L, -1);

    if (prop == NULL) {
        return 0;
    }

//    printf("l_is_internal_prop: %s\n", prop);

    if(getPropForName(prop)) {
        lua_pushboolean(L, 1);
    } else {
        lua_pushboolean(L, 0);
    }

    return 1;
}

static int l_getprop(lua_State *L) {
    const char *prop = lua_tostring(L, -1);

//    printf("l_getprop: %s\n", prop);

    if (!lua_islightuserdata(L, -2)) {
        printf("Error: is not light userdata");
        return 0;
    }

    prop_info_t *propInfo = getPropForName(prop);
    assert(propInfo != NULL);

    auto *entity = (entity_t *) lua_touserdata(L, -2);

    //    printf("Got entity: %d\n", entity->index);
    return propInfo->readFunc(L, entity);
}


static int l_setprop(lua_State *L) {
    // data, prop, value

    const char *prop = lua_tostring(L, -2);
    //printf("l_setprop: %s\n", prop);

    if (!lua_islightuserdata(L, -3)) {
        printf("l_setprop: Error: is not light userdata");
        return 0;
    }

    prop_info_t *propInfo = getPropForName(prop);
    assert(propInfo != NULL);

    auto *entity = (entity_t *) lua_touserdata(L, -3);

    return propInfo->writeFunc(L, entity);
}

int l_assign_entity(lua_State *L) {
//    printf("AssignEntity "); dumpstack(L);
    for(int i = 0; i < MAX_ENTITY; i++) {
        entity_t *entity = &entities[i];
        if(entity->used == 0) {
            entity->used = 1;
            entity->active = 1;
            entity->drawScale = 1.0f;

            lua_pushstring(L, "__data");
            lua_pushlightuserdata(L, entity);
            lua_rawset(L, -3);

            entity->lua_ref = luaL_ref(L, LUA_REGISTRYINDEX);
            break;
        }
    }

    return 0;
}

int l_MSG_ReadInt(lua_State *L) {
    auto *msg = static_cast<msgbuf_t *>(lua_touserdata(L, -1));
    lua_pushinteger(L, *(int *) &msg->buf[msg->pos]);
    msg->pos += 4;
    return 1;
}

int l_init_entity_base(lua_State *L) {
    // -2: RegisterClass Func

    // -1: Class we're registering
    lua_pushcfunction(L, l_is_internal_prop);
    lua_pushcfunction(L, l_getprop);
    lua_pushcfunction(L, l_setprop);

    lua_call(L, 4, 0);
    return 0;
}

void entity_init(lua_State *L) {

    for (int i = 0; i < MAX_ENTITY; i++) {
        entities[i].index = i;
        entities[i].used = 0;
        entities[i].lua_ref = 0;
    }

    int prop_count = 0;
    SETUP_PROP(x);
    SETUP_PROP(y);
    SETUP_PROP(index);
    SETUP_PROP(angle);
    SETUP_PROP(active);
    SETUP_PROP(drawScale);

    for(int i = 0; i < prop_count; i++) {
        prop_info_t *prop = &entity_prop_info[i];

        unsigned long h = hash(prop->name);
        printf("Hash for: %s: %lu\n", prop->name, h);

        assert(entity_prop_info_hashtable[h] == nullptr);
        entity_prop_info_hashtable[h] = prop;
    }

    lua_pushcfunction(L, l_assign_entity);
    lua_setglobal(L, "AssignEntity");

    lua_pushcfunction(L, l_MSG_ReadInt);
    lua_setglobal(L, "MSG_ReadInt");

    lua_pushcfunction(L, l_init_entity_base);
    lua_setglobal(L, "Internal_Init_Entity_Base");
}