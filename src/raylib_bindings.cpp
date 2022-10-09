#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <cstring>
#include "common.h"

#define PROP_INTEGER(name) \
    static int read_##name(lua_State *L, Rectangle *rect) { lua_pushinteger(L, rect->name); return 1; }; \
    static int write_##name(lua_State *L, Rectangle *rect) { rect->name = lua_tointeger(L, -1); return 0; };

static int Vector2_read_x(lua_State *L) {

    if (!lua_isuserdata(L, -1)) {
        dumpstack(L);
        printf("Vector2_read_x: Error: is not userdata\n");
        return 0;
    }

    auto *val = (Vector2 *) lua_touserdata(L, -1);

    lua_pushnumber(L, val->x);
    return 1;
}

static int Vector2_write_x(lua_State *L) {

    if (!lua_isuserdata(L, -2)) {
        printf("Vector2_read_x: Error: is not userdata\n");
        return 0;
    }

    auto *val = (Vector2 *)  lua_touserdata(L, -2);

    val->x = lua_tonumber(L, -1);
    return 1;
}


static int Rectangle_read_y(lua_State *L) {

    if (!lua_isuserdata(L, -1)) {
        dumpstack(L);
        printf("Rectangle_read_y: Error: is not userdata\n");
        return 0;
    }

    auto *rectangle = (Rectangle *) lua_touserdata(L, -1);

    lua_pushnumber(L, rectangle->y);
    return 1;
}

static int Rectangle_set_y(lua_State *L) {

    if (!lua_isuserdata(L, -2)) {
        printf("Rectangle_set_y: Error: is not userdata\n");
        return 0;
    }

    auto *rectangle = (Rectangle *) lua_touserdata(L, -2);

    rectangle->y = lua_tonumber(L, -1);
    return 1;
}

static int Rectangle_Alloc(lua_State *L) {
    Rectangle *rect = (Rectangle *)lua_newuserdata(L, sizeof(Rectangle));
    rect->y = 1023;
    return 1;
}

static int Vector2_Alloc(lua_State *L) {
    auto val = (Vector2 *)lua_newuserdata(L, sizeof(Vector2));
    memset(val, 0, sizeof(Vector2));
    return 1;
}

static int MakeAVector2(lua_State *L) {

    Vector2 temp;
    temp.x = 123;
    temp.y = 456;

    printf("MakeAVector2 ---\n");

    lua_getglobal(L, "rl");
    lua_getfield(L, -1, "Vector2");
    lua_getfield(L, -1, "new");
    lua_pushvalue(L, -2);
    lua_call(L, 1, 1);

    lua_pushstring(L, "@");
    lua_rawget(L, -2);

    auto *userdata = static_cast<Vector2 *>(lua_touserdata(L, -1));
    *userdata = temp;

    lua_pop(L, 1); // pop userdata
    return 1;
}

// Image ImageText(const char *text, int fontSize, Color color);
static int Image_New(lua_State *L) {
    Image image = ImageText("Test", 12, WHITE);

    // Call Image:new()
    // Get the userdata

    auto *image1 = (Image *) lua_touserdata(L, -2);

    *image1 = image;

    // pop or whatever
    return 1;
}

static int DrawRectangle(lua_State *L) {
    // lua: rl.DrawRectangle(rectangle, color)

    if (!lua_isuserdata(L, -2)) {
        printf("DrawRectangle: Error: rectangle is not userdata\n");
        return 0;
    }

    if (!lua_isuserdata(L, -1)) {
        printf("DrawRectangle: Error: color is not userdata\n");
        return 0;
    }

    auto rectangle = *(Rectangle *) lua_touserdata(L, -2);

    auto *color = (Color *)lua_touserdata(L, -2);

    DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, *color);
}



int timeval_subtract(struct timeval *result,
                     struct timeval end,
                     struct timeval start)
{
    if (start.tv_usec < end.tv_usec) {
        int nsec = (end.tv_usec - start.tv_usec) / 1000000 + 1;
        end.tv_usec -= 1000000 * nsec;
        end.tv_sec += nsec;
    }
    if (start.tv_usec - end.tv_usec > 1000000) {
        int nsec = (end.tv_usec - start.tv_usec) / 1000000;
        end.tv_usec += 1000000 * nsec;
        end.tv_sec -= nsec;
    }

    result->tv_sec = end.tv_sec - start.tv_sec;
    result->tv_usec = end.tv_usec - start.tv_usec;

    return end.tv_sec < start.tv_sec;
}

void set_exec_time(int end)
{
    static struct timeval time_start;
    struct timeval time_end;
    struct timeval time_diff;

    if (end) {
        gettimeofday(&time_end, NULL);
        if (timeval_subtract(&time_diff, time_end, time_start) == 0) {
            if (end == 1)
                printf("\nexec time: %1.8fs\n",
                       time_diff.tv_sec + (time_diff.tv_usec / 1000000.0f));
            else if (end == 2)
                printf("%1.8fs",
                       time_diff.tv_sec + (time_diff.tv_usec / 1000000.0f));
        }
        return;
    }
    gettimeofday(&time_start, NULL);
}

void start_exec_timer()
{
    set_exec_time(0);
}

void print_exec_timer()
{
    set_exec_time(1);
}

void init_raylib_bindings(lua_State *L) {
    int result;
//    lua_pushcfunction(L, Rectangle_read_y);
//    lua_setglobal(L, "Rectangle_read_y");
//
//    lua_pushcfunction(L, Rectangle_set_y);
//    lua_setglobal(L, "Rectangle_set_y");
//




//    set_exec_time(0);

    result = luaL_dofile(L, "bind_test.lua");

    if (result) {
        printf("bind_test main.lua: %s\n", lua_tostring(L, -1));
        exit(0);
    }



    lua_getfield(L, -1, "@");
    dumpstack(L);

//    lua_pushcfunction(L, Rectangle_read_y); lua_rawseti(L, -2, 1);
//    lua_pushcfunction(L, Rectangle_set_y); lua_rawseti(L, -2, 2);
    lua_pushcfunction(L, Rectangle_Alloc); lua_setfield(L, -2, "Rectangle_Alloc");

    lua_pushcfunction(L, Rectangle_read_y); lua_setfield(L, -2, "Rectangle_read_y");
    lua_pushcfunction(L, Rectangle_set_y); lua_setfield(L, -2, "Rectangle_set_y");


    lua_pushcfunction(L, Vector2_Alloc); lua_setfield(L, -2, "Vector2_Alloc");
    lua_pushcfunction(L, Vector2_read_x); lua_setfield(L, -2, "Vector2_read_x");
    lua_pushcfunction(L, Vector2_write_x); lua_setfield(L, -2, "Vector2_write_x");

    lua_pop(L, 1);
    dumpstack(L);

    printf("About to register MakeAVector2\n");
    lua_pushcfunction(L, MakeAVector2); lua_setfield(L, -2, "MakeAVector2");
//    lua_pop(L, 1);

    lua_setglobal(L, "rl");

    clock_t start = clock(), diff;
    result = luaL_dofile(L, "rl_test.lua");

    if (result) {
        printf("rl_test: %s\n", lua_tostring(L, -1));
        exit(0);
    }

    diff = clock() - start;
//    set_exec_time(2);
//    printf("Time: %lu\n", diff);

    exit(0);
}


