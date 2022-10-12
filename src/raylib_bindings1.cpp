#include <cstring>
#include "raylib.h"
extern "C" {
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}
static int Rectangle_read_x(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Rectangle_read_x: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_read_x: Error: x is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->x);
	return 1;
}

static int Rectangle_write_x(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Rectangle_write_x: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_write_x: Error: x is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	int _x = lua_tointeger(L, -2);
	_userdata->x = _x;

	return 0;
}

static int Rectangle_read_y(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Rectangle_read_y: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_read_y: Error: y is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->y);
	return 1;
}

static int Rectangle_write_y(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Rectangle_write_y: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_write_y: Error: y is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	int _y = lua_tointeger(L, -2);
	_userdata->y = _y;

	return 0;
}

static int Rectangle_read_width(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Rectangle_read_width: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_read_width: Error: width is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->width);
	return 1;
}

static int Rectangle_write_width(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Rectangle_write_width: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_write_width: Error: width is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	int _width = lua_tointeger(L, -2);
	_userdata->width = _width;

	return 0;
}

static int Rectangle_read_height(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Rectangle_read_height: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_read_height: Error: height is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->height);
	return 1;
}

static int Rectangle_write_height(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Rectangle_write_height: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Rectangle_write_height: Error: height is not userdata\n");
		return 0;
	}
	Rectangle * _userdata = (Rectangle *) lua_touserdata(L, -1);

	int _height = lua_tointeger(L, -2);
	_userdata->height = _height;

	return 0;
}

static int Rectangle_Alloc(lua_State *L) {
	auto val = (Rectangle *) lua_newuserdata(L, sizeof(Rectangle));
	memset(val, 0, sizeof(Rectangle));
	return 1;
}

static int Color_read_r(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Color_read_r: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_read_r: Error: r is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->r);
	return 1;
}

static int Color_write_r(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Color_write_r: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_write_r: Error: r is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	int _r = lua_tointeger(L, -2);
	_userdata->r = _r;

	return 0;
}

static int Color_read_g(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Color_read_g: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_read_g: Error: g is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->g);
	return 1;
}

static int Color_write_g(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Color_write_g: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_write_g: Error: g is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	int _g = lua_tointeger(L, -2);
	_userdata->g = _g;

	return 0;
}

static int Color_read_b(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Color_read_b: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_read_b: Error: b is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->b);
	return 1;
}

static int Color_write_b(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Color_write_b: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_write_b: Error: b is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	int _b = lua_tointeger(L, -2);
	_userdata->b = _b;

	return 0;
}

static int Color_read_a(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Color_read_a: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_read_a: Error: a is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	lua_pushinteger(L, _userdata->a);
	return 1;
}

static int Color_write_a(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Color_write_a: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Color_write_a: Error: a is not userdata\n");
		return 0;
	}
	Color * _userdata = (Color *) lua_touserdata(L, -1);

	int _a = lua_tointeger(L, -2);
	_userdata->a = _a;

	return 0;
}

static int Color_Alloc(lua_State *L) {
	auto val = (Color *) lua_newuserdata(L, sizeof(Color));
	memset(val, 0, sizeof(Color));
	return 1;
}

static int Vector2_read_x(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Vector2_read_x: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Vector2_read_x: Error: x is not userdata\n");
		return 0;
	}
	Vector2 * _userdata = (Vector2 *) lua_touserdata(L, -1);

	lua_pushnumber(L, _userdata->x);
	return 1;
}

static int Vector2_write_x(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Vector2_write_x: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Vector2_write_x: Error: x is not userdata\n");
		return 0;
	}
	Vector2 * _userdata = (Vector2 *) lua_touserdata(L, -1);

	float _x = lua_tonumber(L, -2);
	_userdata->x = _x;

	return 0;
}

static int Vector2_read_y(lua_State *L) {
	if(!lua_istable(L, -1)) {
		printf("Vector2_read_y: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("Vector2_read_y: Error: y is not userdata\n");
		return 0;
	}
	Vector2 * _userdata = (Vector2 *) lua_touserdata(L, -1);

	lua_pushnumber(L, _userdata->y);
	return 1;
}

static int Vector2_write_y(lua_State *L) {
	if(!lua_istable(L, -2)) {
		printf("Vector2_write_y: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("Vector2_write_y: Error: y is not userdata\n");
		return 0;
	}
	Vector2 * _userdata = (Vector2 *) lua_touserdata(L, -1);

	float _y = lua_tonumber(L, -2);
	_userdata->y = _y;

	return 0;
}

static int Vector2_Alloc(lua_State *L) {
	auto val = (Vector2 *) lua_newuserdata(L, sizeof(Vector2));
	memset(val, 0, sizeof(Vector2));
	return 1;
}

static int l_IsKeyPressed(lua_State *L) {
	int key = lua_tointeger(L, -1);
	bool returnVal = IsKeyPressed(key);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_IsKeyDown(lua_State *L) {
	int key = lua_tointeger(L, -1);
	bool returnVal = IsKeyDown(key);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_IsKeyReleased(lua_State *L) {
	int key = lua_tointeger(L, -1);
	bool returnVal = IsKeyReleased(key);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_IsKeyUp(lua_State *L) {
	int key = lua_tointeger(L, -1);
	bool returnVal = IsKeyUp(key);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_DrawText(lua_State *L) {
	const char * text = lua_tostring(L, -5);
	int posX = lua_tointeger(L, -4);
	int posY = lua_tointeger(L, -3);
	int fontSize = lua_tointeger(L, -2);
		if(!lua_istable(L, -1)) {
		printf("DrawText: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("DrawText: Error: color is not userdata\n");
		return 0;
	}
	Color * color = (Color *) lua_touserdata(L, -1);

	DrawText(text, posX, posY, fontSize, *color);
	;
	return 1;
}
static int l_DrawRectangle(lua_State *L) {
	int posX = lua_tointeger(L, -5);
	int posY = lua_tointeger(L, -4);
	int width = lua_tointeger(L, -3);
	int height = lua_tointeger(L, -2);
		if(!lua_istable(L, -1)) {
		printf("DrawRectangle: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -2);
	if(!lua_isuserdata(L, -1)) {
		printf("DrawRectangle: Error: color is not userdata\n");
		return 0;
	}
	Color * color = (Color *) lua_touserdata(L, -1);

	DrawRectangle(posX, posY, width, height, *color);
	;
	return 1;
}
static int l_DrawRectangleLinesEx(lua_State *L) {
		if(!lua_istable(L, -3)) {
		printf("DrawRectangleLinesEx: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -4);
	if(!lua_isuserdata(L, -1)) {
		printf("DrawRectangleLinesEx: Error: rec is not userdata\n");
		return 0;
	}
	Rectangle * rec = (Rectangle *) lua_touserdata(L, -1);

	float lineThick = lua_tonumber(L, -3);
		if(!lua_istable(L, -2)) {
		printf("DrawRectangleLinesEx: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("DrawRectangleLinesEx: Error: color is not userdata\n");
		return 0;
	}
	Color * color = (Color *) lua_touserdata(L, -1);

	DrawRectangleLinesEx(*rec, lineThick, *color);
	;
	return 1;
}
static int l_ColorAlpha(lua_State *L) {
		if(!lua_istable(L, -2)) {
		printf("ColorAlpha: Error: Not a table\n");
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, -3);
	if(!lua_isuserdata(L, -1)) {
		printf("ColorAlpha: Error: color is not userdata\n");
		return 0;
	}
	Color * color = (Color *) lua_touserdata(L, -1);

	float alpha = lua_tonumber(L, -2);
	Color returnVal = ColorAlpha(*color, alpha);
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Color");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Color *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
	return 1;
}
void init_raylib_bindings1(lua_State *L) {
	lua_createtable(L, 0, 200);
	lua_createtable(L, 0, 200);
	lua_setfield(L, -2, "@");
	lua_getfield(L, -1, "@");
	lua_pushcfunction(L, Rectangle_read_x);
	lua_setfield(L, -2, "Rectangle_read_x");
	lua_pushcfunction(L, Rectangle_write_x);
	lua_setfield(L, -2, "Rectangle_write_x");
	lua_pushcfunction(L, Rectangle_read_y);
	lua_setfield(L, -2, "Rectangle_read_y");
	lua_pushcfunction(L, Rectangle_write_y);
	lua_setfield(L, -2, "Rectangle_write_y");
	lua_pushcfunction(L, Rectangle_read_width);
	lua_setfield(L, -2, "Rectangle_read_width");
	lua_pushcfunction(L, Rectangle_write_width);
	lua_setfield(L, -2, "Rectangle_write_width");
	lua_pushcfunction(L, Rectangle_read_height);
	lua_setfield(L, -2, "Rectangle_read_height");
	lua_pushcfunction(L, Rectangle_write_height);
	lua_setfield(L, -2, "Rectangle_write_height");
	lua_pushcfunction(L, Rectangle_Alloc);
	lua_setfield(L, -2, "Rectangle_Alloc");
	lua_pushcfunction(L, Color_read_r);
	lua_setfield(L, -2, "Color_read_r");
	lua_pushcfunction(L, Color_write_r);
	lua_setfield(L, -2, "Color_write_r");
	lua_pushcfunction(L, Color_read_g);
	lua_setfield(L, -2, "Color_read_g");
	lua_pushcfunction(L, Color_write_g);
	lua_setfield(L, -2, "Color_write_g");
	lua_pushcfunction(L, Color_read_b);
	lua_setfield(L, -2, "Color_read_b");
	lua_pushcfunction(L, Color_write_b);
	lua_setfield(L, -2, "Color_write_b");
	lua_pushcfunction(L, Color_read_a);
	lua_setfield(L, -2, "Color_read_a");
	lua_pushcfunction(L, Color_write_a);
	lua_setfield(L, -2, "Color_write_a");
	lua_pushcfunction(L, Color_Alloc);
	lua_setfield(L, -2, "Color_Alloc");
	lua_pushcfunction(L, Vector2_read_x);
	lua_setfield(L, -2, "Vector2_read_x");
	lua_pushcfunction(L, Vector2_write_x);
	lua_setfield(L, -2, "Vector2_write_x");
	lua_pushcfunction(L, Vector2_read_y);
	lua_setfield(L, -2, "Vector2_read_y");
	lua_pushcfunction(L, Vector2_write_y);
	lua_setfield(L, -2, "Vector2_write_y");
	lua_pushcfunction(L, Vector2_Alloc);
	lua_setfield(L, -2, "Vector2_Alloc");
	lua_pop(L, 1);
	lua_pushcfunction(L, l_IsKeyPressed);
	lua_setfield(L, -2, "IsKeyPressed");
	lua_pushcfunction(L, l_IsKeyDown);
	lua_setfield(L, -2, "IsKeyDown");
	lua_pushcfunction(L, l_IsKeyReleased);
	lua_setfield(L, -2, "IsKeyReleased");
	lua_pushcfunction(L, l_IsKeyUp);
	lua_setfield(L, -2, "IsKeyUp");
	lua_pushcfunction(L, l_DrawText);
	lua_setfield(L, -2, "DrawText");
	lua_pushcfunction(L, l_DrawRectangle);
	lua_setfield(L, -2, "DrawRectangle");
	lua_pushcfunction(L, l_DrawRectangleLinesEx);
	lua_setfield(L, -2, "DrawRectangleLinesEx");
	lua_pushcfunction(L, l_ColorAlpha);
	lua_setfield(L, -2, "ColorAlpha");
	lua_setglobal(L, "rl");
}

