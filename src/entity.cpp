
#include <cstring>
#include <cassert>
#include "common.h"

typedef int (*propFunc)(lua_State *L, entity_t *entity);

struct entity_prop_info_t {
    const char *name;
    propFunc readFunc;
    propFunc writeFunc;
};

entity_prop_info_t *entity_prop_info_hashtable[128];
entity_prop_info_t entity_prop_info[10];
entity_t entities[MAX_ENTITY];

static unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) * 33 + c; /* hash * 33 + c */

//        printf("original hash %lu\n", hash);
    return hash & 0x7f;
}

#define PROP_INTEGER(name) \
    static int read_##name(lua_State *L, entity_t *entity) { lua_pushinteger(L, entity->name); return 1; }; \
    static int write_##name(lua_State *L, entity_t *entity) { entity->name = lua_tointeger(L, -1); return 0; };

PROP_INTEGER(x);
PROP_INTEGER(y);
PROP_INTEGER(index);

static entity_prop_info_t *getPropForName(const char *name) {
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

    entity_prop_info_t *propInfo = getPropForName(prop);
    assert(propInfo != NULL);

    entity_t *entity = (entity_t *) lua_touserdata(L, -2);

    //    printf("Got entity: %d\n", entity->index);
    return propInfo->readFunc(L, entity);
}


static int l_setprop(lua_State *L) {
    // data, prop, value

    const char *prop = lua_tostring(L, -2);
//    printf("l_setprop: %s\n", prop);

    if (!lua_islightuserdata(L, -3)) {
        printf("l_setprop: Error: is not light userdata");
        return 0;
    }

    entity_prop_info_t *propInfo = getPropForName(prop);
    assert(propInfo != NULL);

    entity_t *entity = (entity_t *) lua_touserdata(L, -3);

    return propInfo->writeFunc(L, entity);
}

int l_assign_entity(lua_State *L) {
//    printf("AssignEntity "); dumpstack(L);
    for(int i = 0; i < MAX_ENTITY; i++) {
        entity_t *entity = &entities[i];
        if(entity->used == 0) {
            entity->used = 1;

            lua_pushstring(L, "__data");
            lua_pushlightuserdata(L, entity);
            lua_rawset(L, -3);

            entity->lua_ref = luaL_ref(L, LUA_REGISTRYINDEX);
            return 0;
        }
    }

    return 0;
}

void entity_init(lua_State *L) {

    for (int i = 0; i < MAX_ENTITY; i++) {
        entities[i].index = i;
        entities[i].used = 0;
        entities[i].lua_ref = 0;
    }

    entity_prop_info[0].name = "x";
    entity_prop_info[0].readFunc = read_x;
    entity_prop_info[0].writeFunc = write_x;

    entity_prop_info[1].name = "y";
    entity_prop_info[1].readFunc = read_y;
    entity_prop_info[1].writeFunc = write_y;

    entity_prop_info[2].name = "index";
    entity_prop_info[2].readFunc = read_index;
    entity_prop_info[2].writeFunc = write_index;

    for(int i = 0; i < 3; i++) {
        entity_prop_info_t *prop = &entity_prop_info[i];

        unsigned long h = hash(prop->name);
//        printf("Hash for: %s: %lu\n", prop->name, h);

        assert(entity_prop_info_hashtable[h] == NULL);
        entity_prop_info_hashtable[h] = prop;
    }

    lua_pushcfunction(L, l_is_internal_prop);
    lua_setglobal(L, "isInternalProp");

    lua_pushcfunction(L, l_getprop);
    lua_setglobal(L, "getProp");

    lua_pushcfunction(L, l_setprop);
    lua_setglobal(L, "setProp");

    lua_pushcfunction(L, l_assign_entity);
    lua_setglobal(L, "AssignEntity");
}