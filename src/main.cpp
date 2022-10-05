#include <string>
#include <raylib.h>
#include "rlgl.h"

#include <cassert>
#include "common.h"
#include "art.h"

// https://stackoverflow.com/questions/42735621/link-c-variable-to-lua
// http://lua-users.org/wiki/MetatableEvents
// http://www.cse.yorku.ca/~oz/hash.html
// https://stackoverflow.com/questions/59091462/from-c-how-can-i-print-the-contents-of-the-lua-stack
// https://stackoverflow.com/questions/12441593/lua-accessing-a-tables-keys-and-values

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

int l_iskeypressed(lua_State *L) {
    lua_pushboolean(L, IsKeyPressed(lua_tonumber(L, -1)));
    return 1;
}

void DrawVectorArt(VectorArt *art) {
    rlColor3f(0, 0, 0);

    rlBegin(RL_LINES);
    for(int i = 0; i < art->num_lines; i ++) {
        rlVertex3f(art->art[i * 2].x, 0, art->art[i * 2].y);
        rlVertex3f(art->art[i * 2 + 1].x, 0, art->art[i * 2 + 1].y);
    }
    rlEnd();
}

int main(int argc, const char *argv[]) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    lua_pushcfunction(L, _traceback);
    assert(lua_gettop(L) == 1);

    lua_pushcfunction(L, l_iskeydown);
    lua_setglobal(L, "IsKeyDown");

    lua_pushcfunction(L, l_iskeypressed);
    lua_setglobal(L, "IsKeyPressed");

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

    lua_createtable(L, 0, 10);
    lua_setglobal(L, "resources");

    lua_getglobal(L, "resources");
    lua_pushlightuserdata(L, &player_ship);
    lua_setfield(L, -2,  "player_ship");
    lua_pushlightuserdata(L, &shot);
    lua_setfield(L, -2,  "shot");
    lua_pop(L, 1);

    lua_getglobal(L, "InitGame");
    lua_call(L, 0, 1);

    int game_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    printf("Game ref: %d\n", game_ref);
    lua_pop(L, 3);
    dumpstack(L);

    msgbuf_t buf{};
    buf.length = 123;

    entity_t *entity = &entities[0];
    lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
    lua_getfield(L, -1, "ReadFromSnapshot");
    lua_pushvalue(L, -2);
    lua_pushlightuserdata(L, &buf);
    lua_call(L, 2, 0);

////    lua_getglobal(L, "runstuff");
//    lua_call(L, 0, 0);

    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60);

    Model m = LoadModel("./untitled.obj");
    Camera camera = { 0 };
//    camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.position = Vector3{ 0.0f, 40.0f, 0.0f }; // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
//    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.up = Vector3{ 0.0f, 0.0f, -1.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

//    Mesh mesh = GenMeshCube(1, 1, 1);
//    Model m = LoadModelFromMesh(mesh);
    while (!WindowShouldClose())
    {
        lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
        lua_getfield(L, -1, "Update");
        lua_call(L, 0, 0);

        for(int i = 0; i < MAX_ENTITY; i++) {
            entity = &entities[i];
            if(entity->used && entity->active) {
                if(entity->lua_ref) {
                    lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
                    lua_getfield(L, -1, "Update");
                    lua_pushvalue(L, -2);
                    lua_call(L, 1, 0);
                }

                if(!entity->active) {
                    if(entity->lua_ref) {
                        luaL_unref(L, LUA_REGISTRYINDEX, entity->lua_ref);
                    }

                    entity->used = false;
                    entity->lua_ref = 0;
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press arrow keys to move", 190, 200, 20, LIGHTGRAY);
        BeginMode3D(camera);
//

//        rlRotatef(GetTime() * 50, 0, 1, 0);

//        DrawModelWires(m, Vector3{0, 0, 0}, 1.0, BLUE);

//        DrawModel(m, Vector3{0,0,0}, 1.0, BLUE );
        for(int i = 0; i < MAX_ENTITY; i++) {
            entity_t *entity = &entities[i];
            if (entity->used) {

                lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
                lua_getfield(L, -1, "GetDrawable");
                lua_pushvalue(L, -2);
                lua_call(L, 1, 1);

                auto art = (VectorArt *) lua_touserdata(L, -1);

                if(art) {

                    rlPushMatrix();
                    rlTranslatef(entity->x, 0, entity->y);
                    rlScalef(entity->drawScale, entity->drawScale, entity->drawScale);
                    rlRotatef(entity->angle, 0, 1, 0);
                    DrawVectorArt(art);
//                DrawCircle(entity->x, entity->y, 20, RED);
//                DrawRectanglePro(Rectangle{entity->x, entity->y, 20, 20}, Vector2{10, 10}, entity->angle, RED);
                    rlPopMatrix();
                }
            }
        }
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
