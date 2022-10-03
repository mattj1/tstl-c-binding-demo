#pragma once

extern "C" {
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

#define MAX_ENTITY 64

struct entity_t {
    float x;
    float y;
    int index;
    float angle;

    unsigned char used;

    int lua_ref;
};

void entity_init(lua_State *L);
extern entity_t entities[];

void dumpstack(lua_State *L);