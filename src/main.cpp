#include <string>
#import <raylib.h>
#include "common.h"

// https://stackoverflow.com/questions/42735621/link-c-variable-to-lua
// http://lua-users.org/wiki/MetatableEvents
// http://www.cse.yorku.ca/~oz/hash.html
// https://stackoverflow.com/questions/59091462/from-c-how-can-i-print-the-contents-of-the-lua-stack


static int _traceback(lua_State *L) {
    const char *msg = lua_tostring(L, 1);
    if (msg)
        luaL_traceback(L, L, msg, 1);
    else
        lua_pushliteral(L, "no error msg");
    return 1;
}

int l_iskeydown(lua_State *L) {
    lua_pushboolean(L, IsKeyDown(lua_tonumber(L, -1)));
    return 1;
}

int main(int argc, const char *argv[]) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    lua_pushcfunction(L, _traceback);
    assert(lua_gettop(L) == 1);

    lua_pushcfunction(L, l_iskeydown);
    lua_setglobal(L, "IsKeyDown");

    entity_init(L);

    lua_getglobal(L, "package");
    lua_getfield(L, -1, "path"); // get field "path" from table at top of stack (-1)
    std::string cur_path = lua_tostring(L, -1); // grab path string from top of stack
    cur_path.append(";"); // do your path magic here
    cur_path.append("./resources/lua");
    cur_path.append("/?.lua");
    lua_pop(L, 1); // get rid of the string on the stack we just pushed on line 5
    lua_pushstring(L, cur_path.c_str()); // push the new one
    lua_setfield(L, -2, "path"); // set the field "path" in table at -2 with value at top of stack
    lua_pop(L, 1); // get rid of package table from top of stack

    int result;
    result = luaL_dofile(L, "./resources/lua/main.lua");
    if (result) {
        printf("dofile main.lua: %s\n", lua_tostring(L, -1));
        exit(0);
    }

    lua_getfield(L, -1, "InitGame");
    lua_call(L, 0, 1);

    int game_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    printf("Game ref: %d\n", game_ref);
    lua_pop(L, 3);
    dumpstack(L);

    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
        lua_getfield(L, -1, "Update");
        lua_call(L, 0, 0);

        for(int i = 0; i < MAX_ENTITY; i++) {
            entity_t *entity = &entities[i];
            if(entity->used) {
                if(entity->lua_ref) {
                    lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
                    lua_getfield(L, -1, "Update");
                    lua_pushvalue(L, -2);
                    lua_call(L, 1, 0);
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press arrow keys to move", 190, 200, 20, LIGHTGRAY);

        for(int i = 0; i < MAX_ENTITY; i++) {
            entity_t *entity = &entities[i];
            if (entity->used) {
                DrawCircle(entity->x, entity->y, 20, RED);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
