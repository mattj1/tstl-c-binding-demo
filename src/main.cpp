#include <string>
#include <raylib.h>
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

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

Camera camera = { 0 };
static lua_State *L;
static int game_ref;

void UpdateDrawFrame() {

    Vector2 mousePos = GetMousePosition();
    Vector2 v = GetMouseDelta();
    int buttonsDown = 0, buttonsPressed = 0, buttonsReleased = 0;

    for(int i = 0; i < 3; i++) {
        if(IsMouseButtonDown(i)) buttonsDown |= 1 << i;
        if(IsMouseButtonPressed(i)) buttonsPressed |= 1 << i;
        if(IsMouseButtonReleased(i)) buttonsReleased |= 1 << i;
    }

    if(buttonsPressed != 0) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
        lua_getfield(L, -1, "OnMouseDown");
        lua_pushvalue(L, -2);
        lua_pushinteger(L, GetMouseX());
        lua_pushinteger(L, GetMouseY());
        lua_pushinteger(L, buttonsPressed);
        lua_call(L, 4, 0);
    }

    if(buttonsReleased != 0) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
        lua_getfield(L, -1, "OnMouseUp");
        lua_pushvalue(L, -2);
        lua_pushinteger(L, GetMouseX());
        lua_pushinteger(L, GetMouseY());
        lua_pushinteger(L, buttonsReleased);
        lua_call(L, 4, 0);
    }

    if(v.x != 0 || v.y != 0) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
        lua_getfield(L, -1, "OnMouseMove");
        lua_pushvalue(L, -2);
        lua_pushinteger(L, GetMouseX());
        lua_pushinteger(L, GetMouseY());
        lua_pushnumber(L, v.x);
        lua_pushnumber(L, v.y);
        lua_pushinteger(L, buttonsDown);

        lua_call(L, 6, 0);
    }

    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
        lua_getfield(L, -1, "OnMouseWheel");
        lua_pushvalue(L, -2);
        lua_pushnumber(L, wheel);
        lua_call(L, 2, 0);
    }

    entity_t *entity;

    lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
    lua_getfield(L, -1, "Update");
    lua_pushvalue(L, -2);
    lua_call(L, 1, 0);

    lua_pop(L, 1); // pop game ref

    for(int i = 0; i < MAX_ENTITY; i++) {
        entity = &entities[i];
        if(entity->used && entity->active) {
            if(entity->lua_ref) {
                lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
                lua_getfield(L, -1, "Update");
                lua_pushvalue(L, -2);
                lua_call(L, 1, 0);

                lua_pop(L, 1);  // pop lua ref
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

    lua_rawgeti(L, LUA_REGISTRYINDEX, game_ref);
    lua_getfield(L, -1, "Draw");
    lua_pushvalue(L, -2);
    lua_call(L, 1, 0);
    lua_pop(L, 1); // pop game ref

    entity_t *player = &entities[0];
    camera.position = Vector3{ player->x, 40.0f, player->y }; // Camera position
    camera.target = Vector3{ player->x, 0.0f, player->y };      // Camera looking at point
    BeginMode3D(camera);
//        rlRotatef(GetTime() * 50, 0, 1, 0);

//        DrawModelWires(m, Vector3{0, 0, 0}, 1.0, BLUE);

//        DrawModel(m, Vector3{0,0,0}, 1.0, BLUE );

    rlBegin(RL_LINES);
    for(int x = -100; x < 100; x+= 10) {
        rlVertex3f(x, 0, -100);
        rlVertex3f(x, 0, 100);

        rlVertex3f(-100, 0,  x);
        rlVertex3f(100, 0, x);
    }
    rlEnd();

    for(int i = 0; i < MAX_ENTITY; i++) {
        entity_t *entity = &entities[i];
        if (entity->used) {

            lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
            lua_getfield(L, -1, "GetDrawable");
            lua_pushvalue(L, -2);
            lua_call(L, 1, 1);

            auto art = (VectorArt *) lua_touserdata(L, -1);
            lua_pop(L, 1);  // pop userdata
            lua_pop(L, 1);  // pop lua ref

            if(art) {

                rlPushMatrix();
                rlTranslatef(entity->x, 0, entity->y);
                rlScalef(entity->drawScale, entity->drawScale, entity->drawScale);
                rlRotatef(entity->angle, 0, 1, 0);
                DrawVectorArt(art);
                rlPopMatrix();

                rlPushMatrix();

                rlTranslatef(entity->x - 2, 0, entity->y - 2);
                rlScalef(0.1, 0.1, 0.1);
                rlRotatef(entity->angle, 0, 1, 0);
                rlRotatef(90, 1, 0, 0);
                //printf("%d\n", entity->classID);
                if(entity->classID == 3) {
                    DrawText("Planet", 0, 0, 16, BLACK);

                }
//                DrawRectanglePro(Rectangle{entity->x, entity->y, 20, 20}, Vector2{10, 10}, entity->angle, RED);
                rlPopMatrix();
            }
        }
    }
    EndMode3D();

    // DrawText(TextFormat("lua top: %d\n", lua_gettop(L)), 20, 20, 14, BLACK);
    EndDrawing();
}

int l_AllEntities(lua_State *L) {
    int callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
//    printf("l_AllEntities, callback ref: %d\n", callback_ref);
    // -1 = callback
//    dumpstack(L);
    for(int i = 0; i < MAX_ENTITY; i++) {
        entity_t *entity = &entities[i];
        if (entity->used) {
            lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
            lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref); // -2 = callback, -1 = ref
            lua_call(L, 1, 1);
//            printf("stack after call ");
//            dumpstack(L);

            lua_pop(L, 1);  // pop return value
//            lua_pop(L, 1); // pop ref
        }
    }

    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    return 0;
}
extern Vector2 *load_struct_Vector2(lua_State *L, int n, bool optional);
extern Color *load_struct_Color(lua_State *L, int n, bool optional);

int l_DrawSurroundingRectangle(lua_State *L) {
    // Vector, width, height, color...
    Vector2 *pos = load_struct_Vector2(L, -4, false);
    float width = lua_tonumber(L, -3);
    float height = lua_tonumber(L, -2);
    Color *color = load_struct_Color(L, -1, false);

    Vector2 p0 = *pos;
    p0.x -= width / 2;
    p0.y -= height / 2;

    DrawLineV(p0, Vector2{p0.x + 8, p0.y}, *color);
    DrawLineV(p0, Vector2{p0.x, p0.y + 8}, *color);

    p0.x += width;

    DrawLineV(p0, Vector2{p0.x - 8, p0.y}, *color);
    DrawLineV(p0, Vector2{p0.x, p0.y + 8}, *color);

    p0.y += height;
    DrawLineV(p0, Vector2{p0.x - 8, p0.y}, *color);
    DrawLineV(p0, Vector2{p0.x, p0.y - 8}, *color);

    p0.x -= width;
    DrawLineV(p0, Vector2{p0.x + 8, p0.y}, *color);
    DrawLineV(p0, Vector2{p0.x, p0.y - 8}, *color);
    return 0;
}

int main(int argc, const char *argv[]) {
    L = luaL_newstate();
    luaL_openlibs(L);
    lua_pushcfunction(L, _traceback);
    assert(lua_gettop(L) == 1);

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


    // Raylib bindings init =========================================

    extern void init_raylib_bindings1(lua_State *L);
    init_raylib_bindings1(L);

    result = luaL_dofile(L, "resources/raylib_bindings.lua");
    if (result) {
        printf("load raylib_bindings.lua: %s\n", lua_tostring(L, -1));
        exit(0);
    }

    lua_getglobal(L, "rl");
    printf("rl table: "); dumpstack(L);
    result = lua_pcall(L, 1, 0, 0);
    if (result) {
        printf("install raylib bindings: %s\n", lua_tostring(L, -1));
        exit(0);
    }

    // =================================================


    result = luaL_dofile(L, "./resources/lua/main.lua");
//    result = luaL_dofile(L, "./lua/main.lua");
    if (result) {
        printf("dofile main.lua: %s\n", lua_tostring(L, -1));
        exit(0);
    }

    result = luaL_dofile(L, "resources/rl_test.lua");
    if (result) {

        printf("rl_test: %s\n", lua_tostring(L, -1));
        _traceback(L);
        printf("%s\n", lua_tostring(L, -1));
        exit(0);
    }

//    exit(0);

    // Set up resources table

    lua_createtable(L, 0, 10);
    lua_setglobal(L, "resources");

    lua_getglobal(L, "resources");
    lua_pushlightuserdata(L, &player_ship);
    lua_setfield(L, -2,  "player_ship");
    lua_pushlightuserdata(L, &shot);
    lua_setfield(L, -2,  "shot");
    lua_pop(L, 1);

    // Init game

    lua_pushcfunction(L, l_AllEntities);
    lua_setglobal(L, "AllEntities");

    lua_pushcfunction(L, l_DrawSurroundingRectangle);
    lua_setglobal(L, "DrawSurroundingRectangle");

    lua_getglobal(L, "InitGame");
    lua_call(L, 0, 1);

    game_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    printf("Game ref: %d\n", game_ref);

//    msgbuf_t buf{};
//    buf.length = 123;

    entity_t *entity = &entities[0];
//    lua_rawgeti(L, LUA_REGISTRYINDEX, entity->lua_ref);
//    lua_getfield(L, -1, "ReadFromSnapshot");
//    lua_pushvalue(L, -2);
//    lua_pushlightuserdata(L, &buf);
//    lua_call(L, 2, 0);

    InitWindow(800, 600, "raylib [core] example - basic window");



//    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.up = Vector3{ 0.0f, 0.0f, -1.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);
#endif

//    Model m = LoadModel("./untitled.obj");

//    camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position

//    Mesh mesh = GenMeshCube(1, 1, 1);
//    Model m = LoadModelFromMesh(mesh);
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    CloseWindow();
    return 0;
}
