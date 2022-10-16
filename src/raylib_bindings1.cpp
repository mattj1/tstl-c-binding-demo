#include <cstring>
#include <cstdlib>
#include "raylib.h"
#include "raymath.h"
extern "C" {
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}
void *load_member_struct(lua_State *L, int n, const char *member_name) {
    lua_getfield(L, n, member_name);
    lua_pushstring(L, "@"); lua_rawget(L, -2);
    
    void *_val = lua_touserdata(L, -1);
    lua_pop(L, 1); // pop userdata
    lua_pop(L, 1); // pop field
 
    return _val;
}
Rectangle *load_struct_Rectangle(lua_State *L, int n, bool optional) {
	if(!lua_istable(L, n)) {
		if(optional) return nullptr;
		printf("Error: Not a table\n"); exit(0);
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, n - 1);
	if(!lua_isuserdata(L, -1)) {
		printf("Error: not userdata\n"); exit(0);
		return 0;
	}
	Rectangle * _val = (Rectangle *) lua_touserdata(L, -1);
	lua_pop(L, 1); // pop the userdata
	 return _val;
}
Color *load_struct_Color(lua_State *L, int n, bool optional) {
	if(!lua_istable(L, n)) {
		if(optional) return nullptr;
		printf("Error: Not a table\n"); exit(0);
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, n - 1);
	if(!lua_isuserdata(L, -1)) {
		printf("Error: not userdata\n"); exit(0);
		return 0;
	}
	Color * _val = (Color *) lua_touserdata(L, -1);
	lua_pop(L, 1); // pop the userdata
	 return _val;
}
Vector2 *load_struct_Vector2(lua_State *L, int n, bool optional) {
	if(!lua_istable(L, n)) {
		if(optional) return nullptr;
		printf("Error: Not a table\n"); exit(0);
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, n - 1);
	if(!lua_isuserdata(L, -1)) {
		printf("Error: not userdata\n"); exit(0);
		return 0;
	}
	Vector2 * _val = (Vector2 *) lua_touserdata(L, -1);
	lua_pop(L, 1); // pop the userdata
	 return _val;
}
Camera2D *load_struct_Camera2D(lua_State *L, int n, bool optional) {
	if(!lua_istable(L, n)) {
		if(optional) return nullptr;
		printf("Error: Not a table\n"); exit(0);
		return 0;
	}
	lua_pushstring(L, "@"); lua_rawget(L, n - 1);
	if(!lua_isuserdata(L, -1)) {
		printf("Error: not userdata\n"); exit(0);
		return 0;
	}
	Camera2D * _val = (Camera2D *) lua_touserdata(L, -1);
	lua_pop(L, 1); // pop the userdata
	Vector2 * _offset = (Vector2 *) load_member_struct(L, n, "offset");
	_val->offset = *_offset;
	Vector2 * _target = (Vector2 *) load_member_struct(L, n, "target");
	_val->target = *_target;
	 return _val;
}
static int Rectangle_read_x(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushinteger(L, _userdata->x);
	return 1;
}

static int Rectangle_write_x(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	int _x = lua_tointeger(L, -1);
	_userdata->x = _x;

	return 0;
}

static int Rectangle_read_y(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushinteger(L, _userdata->y);
	return 1;
}

static int Rectangle_write_y(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	int _y = lua_tointeger(L, -1);
	_userdata->y = _y;

	return 0;
}

static int Rectangle_read_width(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushinteger(L, _userdata->width);
	return 1;
}

static int Rectangle_write_width(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	int _width = lua_tointeger(L, -1);
	_userdata->width = _width;

	return 0;
}

static int Rectangle_read_height(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushinteger(L, _userdata->height);
	return 1;
}

static int Rectangle_write_height(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	int _height = lua_tointeger(L, -1);
	_userdata->height = _height;

	return 0;
}

static int Rectangle_Alloc(lua_State *L) {
	auto val = (Rectangle *) lua_newuserdata(L, sizeof(Rectangle));
	memset(val, 0, sizeof(Rectangle));
	return 1;
}

static int Color_read_r(lua_State *L) {
Color * _userdata = load_struct_Color(L, -1, false);
	lua_pushinteger(L, _userdata->r);
	return 1;
}

static int Color_write_r(lua_State *L) {
Color * _userdata = load_struct_Color(L, -2, false);
	int _r = lua_tointeger(L, -1);
	_userdata->r = _r;

	return 0;
}

static int Color_read_g(lua_State *L) {
Color * _userdata = load_struct_Color(L, -1, false);
	lua_pushinteger(L, _userdata->g);
	return 1;
}

static int Color_write_g(lua_State *L) {
Color * _userdata = load_struct_Color(L, -2, false);
	int _g = lua_tointeger(L, -1);
	_userdata->g = _g;

	return 0;
}

static int Color_read_b(lua_State *L) {
Color * _userdata = load_struct_Color(L, -1, false);
	lua_pushinteger(L, _userdata->b);
	return 1;
}

static int Color_write_b(lua_State *L) {
Color * _userdata = load_struct_Color(L, -2, false);
	int _b = lua_tointeger(L, -1);
	_userdata->b = _b;

	return 0;
}

static int Color_read_a(lua_State *L) {
Color * _userdata = load_struct_Color(L, -1, false);
	lua_pushinteger(L, _userdata->a);
	return 1;
}

static int Color_write_a(lua_State *L) {
Color * _userdata = load_struct_Color(L, -2, false);
	int _a = lua_tointeger(L, -1);
	_userdata->a = _a;

	return 0;
}

static int Color_Alloc(lua_State *L) {
	auto val = (Color *) lua_newuserdata(L, sizeof(Color));
	memset(val, 0, sizeof(Color));
	return 1;
}

static int Vector2_read_x(lua_State *L) {
Vector2 * _userdata = load_struct_Vector2(L, -1, false);
	lua_pushnumber(L, _userdata->x);
	return 1;
}

static int Vector2_write_x(lua_State *L) {
Vector2 * _userdata = load_struct_Vector2(L, -2, false);
	float _x = lua_tonumber(L, -1);
	_userdata->x = _x;

	return 0;
}

static int Vector2_read_y(lua_State *L) {
Vector2 * _userdata = load_struct_Vector2(L, -1, false);
	lua_pushnumber(L, _userdata->y);
	return 1;
}

static int Vector2_write_y(lua_State *L) {
Vector2 * _userdata = load_struct_Vector2(L, -2, false);
	float _y = lua_tonumber(L, -1);
	_userdata->y = _y;

	return 0;
}

static int Vector2_Alloc(lua_State *L) {
	auto val = (Vector2 *) lua_newuserdata(L, sizeof(Vector2));
	memset(val, 0, sizeof(Vector2));
	return 1;
}

static int Camera2D_read_rotation(lua_State *L) {
Camera2D * _userdata = load_struct_Camera2D(L, -1, false);
	lua_pushnumber(L, _userdata->rotation);
	return 1;
}

static int Camera2D_write_rotation(lua_State *L) {
Camera2D * _userdata = load_struct_Camera2D(L, -2, false);
	float _rotation = lua_tonumber(L, -1);
	_userdata->rotation = _rotation;

	return 0;
}

static int Camera2D_read_zoom(lua_State *L) {
Camera2D * _userdata = load_struct_Camera2D(L, -1, false);
	lua_pushnumber(L, _userdata->zoom);
	return 1;
}

static int Camera2D_write_zoom(lua_State *L) {
Camera2D * _userdata = load_struct_Camera2D(L, -2, false);
	float _zoom = lua_tonumber(L, -1);
	_userdata->zoom = _zoom;

	return 0;
}

static int Camera2D_Alloc(lua_State *L) {
	auto val = (Camera2D *) lua_newuserdata(L, sizeof(Camera2D));
	memset(val, 0, sizeof(Camera2D));
	return 1;
}

static int l_BeginMode2D(lua_State *L) {
	Camera2D * camera = load_struct_Camera2D(L, -1, false);
	BeginMode2D(*camera);
	;
	return 1;
}
static int l_EndMode2D(lua_State *L) {
	EndMode2D();
	;
	return 1;
}
static int l_GetScreenToWorld2D(lua_State *L) {
	Vector2 * position = load_struct_Vector2(L, -2, false);
	Camera2D * camera = load_struct_Camera2D(L, -1, false);
	Vector2 returnVal = GetScreenToWorld2D(*position, *camera);
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Vector2");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Vector2 *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
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
static int l_IsMouseButtonDown(lua_State *L) {
	int button = lua_tointeger(L, -1);
	bool returnVal = IsMouseButtonDown(button);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_GetMousePosition(lua_State *L) {
	Vector2 returnVal = GetMousePosition();
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Vector2");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Vector2 *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
	return 1;
}
static int l_GetMouseDelta(lua_State *L) {
	Vector2 returnVal = GetMouseDelta();
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Vector2");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Vector2 *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
	return 1;
}
static int l_DrawText(lua_State *L) {
	const char * text = lua_tostring(L, -5);
	int posX = lua_tointeger(L, -4);
	int posY = lua_tointeger(L, -3);
	int fontSize = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawText(text, posX, posY, fontSize, *color);
	;
	return 1;
}
static int l_DrawLine(lua_State *L) {
	float startPosX = lua_tonumber(L, -5);
	float startPosY = lua_tonumber(L, -4);
	float endPosX = lua_tonumber(L, -3);
	float endPosY = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLine(startPosX, startPosY, endPosX, endPosY, *color);
	;
	return 1;
}
static int l_DrawCircle(lua_State *L) {
	float centerX = lua_tonumber(L, -4);
	float centerY = lua_tonumber(L, -3);
	float radius = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawCircle(centerX, centerY, radius, *color);
	;
	return 1;
}
static int l_DrawRectangle(lua_State *L) {
	int posX = lua_tointeger(L, -5);
	int posY = lua_tointeger(L, -4);
	int width = lua_tointeger(L, -3);
	int height = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangle(posX, posY, width, height, *color);
	;
	return 1;
}
static int l_DrawRectangleLinesEx(lua_State *L) {
	Rectangle * rec = load_struct_Rectangle(L, -3, false);
	float lineThick = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangleLinesEx(*rec, lineThick, *color);
	;
	return 1;
}
static int l_CheckCollisionLines(lua_State *L) {
	Vector2 * startPos1 = load_struct_Vector2(L, -5, false);
	Vector2 * endPos1 = load_struct_Vector2(L, -4, false);
	Vector2 * startPos2 = load_struct_Vector2(L, -3, false);
	Vector2 * endPos2 = load_struct_Vector2(L, -2, false);
		Vector2 * collisionPoint = load_struct_Vector2(L, -1, true);
	bool returnVal = CheckCollisionLines(*startPos1, *endPos1, *startPos2, *endPos2, collisionPoint);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_ColorAlpha(lua_State *L) {
	Color * color = load_struct_Color(L, -2, false);
	float alpha = lua_tonumber(L, -1);
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
static int l_Vector2Scale(lua_State *L) {
	Vector2 * v = load_struct_Vector2(L, -2, false);
	float scale = lua_tonumber(L, -1);
	Vector2 returnVal = Vector2Scale(*v, scale);
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Vector2");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Vector2 *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
	return 1;
}
static int l_Vector2Add(lua_State *L) {
	Vector2 * v1 = load_struct_Vector2(L, -2, false);
	Vector2 * v2 = load_struct_Vector2(L, -1, false);
	Vector2 returnVal = Vector2Add(*v1, *v2);
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Vector2");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Vector2 *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
	return 1;
}
static int l_Vector2Distance(lua_State *L) {
	Vector2 * v1 = load_struct_Vector2(L, -2, false);
	Vector2 * v2 = load_struct_Vector2(L, -1, false);
	float returnVal = Vector2Distance(*v1, *v2);
	lua_pushnumber(L, returnVal);
	return 1;
}
static int l_Vector2DistanceSqr(lua_State *L) {
	Vector2 * v1 = load_struct_Vector2(L, -2, false);
	Vector2 * v2 = load_struct_Vector2(L, -1, false);
	float returnVal = Vector2DistanceSqr(*v1, *v2);
	lua_pushnumber(L, returnVal);
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
	lua_pushcfunction(L, Camera2D_read_rotation);
	lua_setfield(L, -2, "Camera2D_read_rotation");
	lua_pushcfunction(L, Camera2D_write_rotation);
	lua_setfield(L, -2, "Camera2D_write_rotation");
	lua_pushcfunction(L, Camera2D_read_zoom);
	lua_setfield(L, -2, "Camera2D_read_zoom");
	lua_pushcfunction(L, Camera2D_write_zoom);
	lua_setfield(L, -2, "Camera2D_write_zoom");
	lua_pushcfunction(L, Camera2D_Alloc);
	lua_setfield(L, -2, "Camera2D_Alloc");
	lua_pop(L, 1);
	lua_pushcfunction(L, l_BeginMode2D);
	lua_setfield(L, -2, "BeginMode2D");
	lua_pushcfunction(L, l_EndMode2D);
	lua_setfield(L, -2, "EndMode2D");
	lua_pushcfunction(L, l_GetScreenToWorld2D);
	lua_setfield(L, -2, "GetScreenToWorld2D");
	lua_pushcfunction(L, l_IsKeyPressed);
	lua_setfield(L, -2, "IsKeyPressed");
	lua_pushcfunction(L, l_IsKeyDown);
	lua_setfield(L, -2, "IsKeyDown");
	lua_pushcfunction(L, l_IsKeyReleased);
	lua_setfield(L, -2, "IsKeyReleased");
	lua_pushcfunction(L, l_IsKeyUp);
	lua_setfield(L, -2, "IsKeyUp");
	lua_pushcfunction(L, l_IsMouseButtonDown);
	lua_setfield(L, -2, "IsMouseButtonDown");
	lua_pushcfunction(L, l_GetMousePosition);
	lua_setfield(L, -2, "GetMousePosition");
	lua_pushcfunction(L, l_GetMouseDelta);
	lua_setfield(L, -2, "GetMouseDelta");
	lua_pushcfunction(L, l_DrawText);
	lua_setfield(L, -2, "DrawText");
	lua_pushcfunction(L, l_DrawLine);
	lua_setfield(L, -2, "DrawLine");
	lua_pushcfunction(L, l_DrawCircle);
	lua_setfield(L, -2, "DrawCircle");
	lua_pushcfunction(L, l_DrawRectangle);
	lua_setfield(L, -2, "DrawRectangle");
	lua_pushcfunction(L, l_DrawRectangleLinesEx);
	lua_setfield(L, -2, "DrawRectangleLinesEx");
	lua_pushcfunction(L, l_CheckCollisionLines);
	lua_setfield(L, -2, "CheckCollisionLines");
	lua_pushcfunction(L, l_ColorAlpha);
	lua_setfield(L, -2, "ColorAlpha");
	lua_pushcfunction(L, l_Vector2Scale);
	lua_setfield(L, -2, "Vector2Scale");
	lua_pushcfunction(L, l_Vector2Add);
	lua_setfield(L, -2, "Vector2Add");
	lua_pushcfunction(L, l_Vector2Distance);
	lua_setfield(L, -2, "Vector2Distance");
	lua_pushcfunction(L, l_Vector2DistanceSqr);
	lua_setfield(L, -2, "Vector2DistanceSqr");
	lua_setglobal(L, "rl");
}

