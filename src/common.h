#pragma once

#include "raylib.h"

extern "C" {
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

#define MAX_ENTITY 64

struct VectorArt {
    int num_lines;
    Vector2 *art;
};

struct entity_t {
    float x;
    float y;
    int index;
    float angle;
    float drawScale;
    int classID;

    unsigned char active;
    unsigned char used;

    int lua_ref;
};

typedef int (*propFunc)(lua_State *L, entity_t *entity);

struct prop_info_t {
    const char *name;
    propFunc readFunc;
    propFunc writeFunc;
};

struct msgbuf_t {
    char buf[0x2000];
    int length;

    int pos;
};

void entity_init(lua_State *L);
extern entity_t entities[];

void dumpstack(lua_State *L);