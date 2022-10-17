#include <cstring>
#include <cstdlib>
#include "raylib.h"
#include "rlgl.h"
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
Vector3 *load_struct_Vector3(lua_State *L, int n, bool optional) {
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
	Vector3 * _val = (Vector3 *) lua_touserdata(L, -1);
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
Camera3D *load_struct_Camera3D(lua_State *L, int n, bool optional) {
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
	Camera3D * _val = (Camera3D *) lua_touserdata(L, -1);
	lua_pop(L, 1); // pop the userdata
	Vector3 * _position = (Vector3 *) load_member_struct(L, n, "position");
	_val->position = *_position;
	Vector3 * _target = (Vector3 *) load_member_struct(L, n, "target");
	_val->target = *_target;
	Vector3 * _up = (Vector3 *) load_member_struct(L, n, "up");
	_val->up = *_up;
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

static int Vector3_read_x(lua_State *L) {
Vector3 * _userdata = load_struct_Vector3(L, -1, false);
	lua_pushnumber(L, _userdata->x);
	return 1;
}

static int Vector3_write_x(lua_State *L) {
Vector3 * _userdata = load_struct_Vector3(L, -2, false);
	float _x = lua_tonumber(L, -1);
	_userdata->x = _x;

	return 0;
}

static int Vector3_read_y(lua_State *L) {
Vector3 * _userdata = load_struct_Vector3(L, -1, false);
	lua_pushnumber(L, _userdata->y);
	return 1;
}

static int Vector3_write_y(lua_State *L) {
Vector3 * _userdata = load_struct_Vector3(L, -2, false);
	float _y = lua_tonumber(L, -1);
	_userdata->y = _y;

	return 0;
}

static int Vector3_read_z(lua_State *L) {
Vector3 * _userdata = load_struct_Vector3(L, -1, false);
	lua_pushnumber(L, _userdata->z);
	return 1;
}

static int Vector3_write_z(lua_State *L) {
Vector3 * _userdata = load_struct_Vector3(L, -2, false);
	float _z = lua_tonumber(L, -1);
	_userdata->z = _z;

	return 0;
}

static int Vector3_Alloc(lua_State *L) {
	auto val = (Vector3 *) lua_newuserdata(L, sizeof(Vector3));
	memset(val, 0, sizeof(Vector3));
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

static int Rectangle_read_x(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushnumber(L, _userdata->x);
	return 1;
}

static int Rectangle_write_x(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	float _x = lua_tonumber(L, -1);
	_userdata->x = _x;

	return 0;
}

static int Rectangle_read_y(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushnumber(L, _userdata->y);
	return 1;
}

static int Rectangle_write_y(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	float _y = lua_tonumber(L, -1);
	_userdata->y = _y;

	return 0;
}

static int Rectangle_read_width(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushnumber(L, _userdata->width);
	return 1;
}

static int Rectangle_write_width(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	float _width = lua_tonumber(L, -1);
	_userdata->width = _width;

	return 0;
}

static int Rectangle_read_height(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -1, false);
	lua_pushnumber(L, _userdata->height);
	return 1;
}

static int Rectangle_write_height(lua_State *L) {
Rectangle * _userdata = load_struct_Rectangle(L, -2, false);
	float _height = lua_tonumber(L, -1);
	_userdata->height = _height;

	return 0;
}

static int Rectangle_Alloc(lua_State *L) {
	auto val = (Rectangle *) lua_newuserdata(L, sizeof(Rectangle));
	memset(val, 0, sizeof(Rectangle));
	return 1;
}

static int Camera3D_read_fovy(lua_State *L) {
Camera3D * _userdata = load_struct_Camera3D(L, -1, false);
	lua_pushnumber(L, _userdata->fovy);
	return 1;
}

static int Camera3D_write_fovy(lua_State *L) {
Camera3D * _userdata = load_struct_Camera3D(L, -2, false);
	float _fovy = lua_tonumber(L, -1);
	_userdata->fovy = _fovy;

	return 0;
}

static int Camera3D_read_projection(lua_State *L) {
Camera3D * _userdata = load_struct_Camera3D(L, -1, false);
	lua_pushinteger(L, _userdata->projection);
	return 1;
}

static int Camera3D_write_projection(lua_State *L) {
Camera3D * _userdata = load_struct_Camera3D(L, -2, false);
	int _projection = lua_tointeger(L, -1);
	_userdata->projection = _projection;

	return 0;
}

static int Camera3D_Alloc(lua_State *L) {
	auto val = (Camera3D *) lua_newuserdata(L, sizeof(Camera3D));
	memset(val, 0, sizeof(Camera3D));
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
static int l_SetExitKey(lua_State *L) {
	int key = lua_tointeger(L, -1);
	SetExitKey(key);
	;
	return 1;
}
static int l_GetKeyPressed(lua_State *L) {
	int returnVal = GetKeyPressed();
	lua_pushinteger(L, returnVal);
	return 1;
}
static int l_GetCharPressed(lua_State *L) {
	int returnVal = GetCharPressed();
	lua_pushinteger(L, returnVal);
	return 1;
}
static int l_ClearBackground(lua_State *L) {
	Color * color = load_struct_Color(L, -1, false);
	ClearBackground(*color);
	;
	return 1;
}
static int l_BeginDrawing(lua_State *L) {
	BeginDrawing();
	;
	return 1;
}
static int l_EndDrawing(lua_State *L) {
	EndDrawing();
	;
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
static int l_BeginMode3D(lua_State *L) {
	Camera3D * camera = load_struct_Camera3D(L, -1, false);
	BeginMode3D(*camera);
	;
	return 1;
}
static int l_EndMode3D(lua_State *L) {
	EndMode3D();
	;
	return 1;
}
static int l_IsMouseButtonPressed(lua_State *L) {
	int button = lua_tointeger(L, -1);
	bool returnVal = IsMouseButtonPressed(button);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_IsMouseButtonDown(lua_State *L) {
	int button = lua_tointeger(L, -1);
	bool returnVal = IsMouseButtonDown(button);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_IsMouseButtonReleased(lua_State *L) {
	int button = lua_tointeger(L, -1);
	bool returnVal = IsMouseButtonReleased(button);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_IsMouseButtonUp(lua_State *L) {
	int button = lua_tointeger(L, -1);
	bool returnVal = IsMouseButtonUp(button);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_GetMouseX(lua_State *L) {
	int returnVal = GetMouseX();
	lua_pushinteger(L, returnVal);
	return 1;
}
static int l_GetMouseY(lua_State *L) {
	int returnVal = GetMouseY();
	lua_pushinteger(L, returnVal);
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
static int l_DrawPixel(lua_State *L) {
	int posX = lua_tointeger(L, -3);
	int posY = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawPixel(posX, posY, *color);
	;
	return 1;
}
static int l_DrawPixelV(lua_State *L) {
	Vector2 * position = load_struct_Vector2(L, -2, false);
	Color * color = load_struct_Color(L, -1, false);
	DrawPixelV(*position, *color);
	;
	return 1;
}
static int l_DrawLine(lua_State *L) {
	int startPosX = lua_tointeger(L, -5);
	int startPosY = lua_tointeger(L, -4);
	int endPosX = lua_tointeger(L, -3);
	int endPosY = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLine(startPosX, startPosY, endPosX, endPosY, *color);
	;
	return 1;
}
static int l_DrawLineV(lua_State *L) {
	Vector2 * startPos = load_struct_Vector2(L, -3, false);
	Vector2 * endPos = load_struct_Vector2(L, -2, false);
	Color * color = load_struct_Color(L, -1, false);
	DrawLineV(*startPos, *endPos, *color);
	;
	return 1;
}
static int l_DrawLineEx(lua_State *L) {
	Vector2 * startPos = load_struct_Vector2(L, -4, false);
	Vector2 * endPos = load_struct_Vector2(L, -3, false);
	float thick = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLineEx(*startPos, *endPos, thick, *color);
	;
	return 1;
}
static int l_DrawLineBezier(lua_State *L) {
	Vector2 * startPos = load_struct_Vector2(L, -4, false);
	Vector2 * endPos = load_struct_Vector2(L, -3, false);
	float thick = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLineBezier(*startPos, *endPos, thick, *color);
	;
	return 1;
}
static int l_DrawLineBezierQuad(lua_State *L) {
	Vector2 * startPos = load_struct_Vector2(L, -5, false);
	Vector2 * endPos = load_struct_Vector2(L, -4, false);
	Vector2 * controlPos = load_struct_Vector2(L, -3, false);
	float thick = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLineBezierQuad(*startPos, *endPos, *controlPos, thick, *color);
	;
	return 1;
}
static int l_DrawLineBezierCubic(lua_State *L) {
	Vector2 * startPos = load_struct_Vector2(L, -6, false);
	Vector2 * endPos = load_struct_Vector2(L, -5, false);
	Vector2 * startControlPos = load_struct_Vector2(L, -4, false);
	Vector2 * endControlPos = load_struct_Vector2(L, -3, false);
	float thick = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLineBezierCubic(*startPos, *endPos, *startControlPos, *endControlPos, thick, *color);
	;
	return 1;
}
static int l_DrawLineStrip(lua_State *L) {
		Vector2 * points = load_struct_Vector2(L, -3, true);
	int pointCount = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawLineStrip(points, pointCount, *color);
	;
	return 1;
}
static int l_DrawCircle(lua_State *L) {
	int centerX = lua_tointeger(L, -4);
	int centerY = lua_tointeger(L, -3);
	float radius = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawCircle(centerX, centerY, radius, *color);
	;
	return 1;
}
static int l_DrawCircleSector(lua_State *L) {
	Vector2 * center = load_struct_Vector2(L, -6, false);
	float radius = lua_tonumber(L, -5);
	float startAngle = lua_tonumber(L, -4);
	float endAngle = lua_tonumber(L, -3);
	int segments = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawCircleSector(*center, radius, startAngle, endAngle, segments, *color);
	;
	return 1;
}
static int l_DrawCircleSectorLines(lua_State *L) {
	Vector2 * center = load_struct_Vector2(L, -6, false);
	float radius = lua_tonumber(L, -5);
	float startAngle = lua_tonumber(L, -4);
	float endAngle = lua_tonumber(L, -3);
	int segments = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawCircleSectorLines(*center, radius, startAngle, endAngle, segments, *color);
	;
	return 1;
}
static int l_DrawCircleGradient(lua_State *L) {
	int centerX = lua_tointeger(L, -5);
	int centerY = lua_tointeger(L, -4);
	float radius = lua_tonumber(L, -3);
	Color * color1 = load_struct_Color(L, -2, false);
	Color * color2 = load_struct_Color(L, -1, false);
	DrawCircleGradient(centerX, centerY, radius, *color1, *color2);
	;
	return 1;
}
static int l_DrawCircleV(lua_State *L) {
	Vector2 * center = load_struct_Vector2(L, -3, false);
	float radius = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawCircleV(*center, radius, *color);
	;
	return 1;
}
static int l_DrawCircleLines(lua_State *L) {
	int centerX = lua_tointeger(L, -4);
	int centerY = lua_tointeger(L, -3);
	float radius = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawCircleLines(centerX, centerY, radius, *color);
	;
	return 1;
}
static int l_DrawEllipse(lua_State *L) {
	int centerX = lua_tointeger(L, -5);
	int centerY = lua_tointeger(L, -4);
	float radiusH = lua_tonumber(L, -3);
	float radiusV = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawEllipse(centerX, centerY, radiusH, radiusV, *color);
	;
	return 1;
}
static int l_DrawEllipseLines(lua_State *L) {
	int centerX = lua_tointeger(L, -5);
	int centerY = lua_tointeger(L, -4);
	float radiusH = lua_tonumber(L, -3);
	float radiusV = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawEllipseLines(centerX, centerY, radiusH, radiusV, *color);
	;
	return 1;
}
static int l_DrawRing(lua_State *L) {
	Vector2 * center = load_struct_Vector2(L, -7, false);
	float innerRadius = lua_tonumber(L, -6);
	float outerRadius = lua_tonumber(L, -5);
	float startAngle = lua_tonumber(L, -4);
	float endAngle = lua_tonumber(L, -3);
	int segments = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRing(*center, innerRadius, outerRadius, startAngle, endAngle, segments, *color);
	;
	return 1;
}
static int l_DrawRingLines(lua_State *L) {
	Vector2 * center = load_struct_Vector2(L, -7, false);
	float innerRadius = lua_tonumber(L, -6);
	float outerRadius = lua_tonumber(L, -5);
	float startAngle = lua_tonumber(L, -4);
	float endAngle = lua_tonumber(L, -3);
	int segments = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRingLines(*center, innerRadius, outerRadius, startAngle, endAngle, segments, *color);
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
static int l_DrawRectangleV(lua_State *L) {
	Vector2 * position = load_struct_Vector2(L, -3, false);
	Vector2 * size = load_struct_Vector2(L, -2, false);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangleV(*position, *size, *color);
	;
	return 1;
}
static int l_DrawRectangleRec(lua_State *L) {
	Rectangle * rec = load_struct_Rectangle(L, -2, false);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangleRec(*rec, *color);
	;
	return 1;
}
static int l_DrawRectanglePro(lua_State *L) {
	Rectangle * rec = load_struct_Rectangle(L, -4, false);
	Vector2 * origin = load_struct_Vector2(L, -3, false);
	float rotation = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectanglePro(*rec, *origin, rotation, *color);
	;
	return 1;
}
static int l_DrawRectangleGradientV(lua_State *L) {
	int posX = lua_tointeger(L, -6);
	int posY = lua_tointeger(L, -5);
	int width = lua_tointeger(L, -4);
	int height = lua_tointeger(L, -3);
	Color * color1 = load_struct_Color(L, -2, false);
	Color * color2 = load_struct_Color(L, -1, false);
	DrawRectangleGradientV(posX, posY, width, height, *color1, *color2);
	;
	return 1;
}
static int l_DrawRectangleGradientH(lua_State *L) {
	int posX = lua_tointeger(L, -6);
	int posY = lua_tointeger(L, -5);
	int width = lua_tointeger(L, -4);
	int height = lua_tointeger(L, -3);
	Color * color1 = load_struct_Color(L, -2, false);
	Color * color2 = load_struct_Color(L, -1, false);
	DrawRectangleGradientH(posX, posY, width, height, *color1, *color2);
	;
	return 1;
}
static int l_DrawRectangleGradientEx(lua_State *L) {
	Rectangle * rec = load_struct_Rectangle(L, -5, false);
	Color * col1 = load_struct_Color(L, -4, false);
	Color * col2 = load_struct_Color(L, -3, false);
	Color * col3 = load_struct_Color(L, -2, false);
	Color * col4 = load_struct_Color(L, -1, false);
	DrawRectangleGradientEx(*rec, *col1, *col2, *col3, *col4);
	;
	return 1;
}
static int l_DrawRectangleLines(lua_State *L) {
	int posX = lua_tointeger(L, -5);
	int posY = lua_tointeger(L, -4);
	int width = lua_tointeger(L, -3);
	int height = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangleLines(posX, posY, width, height, *color);
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
static int l_DrawRectangleRounded(lua_State *L) {
	Rectangle * rec = load_struct_Rectangle(L, -4, false);
	float roundness = lua_tonumber(L, -3);
	int segments = lua_tointeger(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangleRounded(*rec, roundness, segments, *color);
	;
	return 1;
}
static int l_DrawRectangleRoundedLines(lua_State *L) {
	Rectangle * rec = load_struct_Rectangle(L, -5, false);
	float roundness = lua_tonumber(L, -4);
	int segments = lua_tointeger(L, -3);
	float lineThick = lua_tonumber(L, -2);
	Color * color = load_struct_Color(L, -1, false);
	DrawRectangleRoundedLines(*rec, roundness, segments, lineThick, *color);
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
static int l_CheckCollisionRecs(lua_State *L) {
	Rectangle * rec1 = load_struct_Rectangle(L, -2, false);
	Rectangle * rec2 = load_struct_Rectangle(L, -1, false);
	bool returnVal = CheckCollisionRecs(*rec1, *rec2);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_CheckCollisionCircles(lua_State *L) {
	Vector2 * center1 = load_struct_Vector2(L, -4, false);
	float radius1 = lua_tonumber(L, -3);
	Vector2 * center2 = load_struct_Vector2(L, -2, false);
	float radius2 = lua_tonumber(L, -1);
	bool returnVal = CheckCollisionCircles(*center1, radius1, *center2, radius2);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_CheckCollisionCircleRec(lua_State *L) {
	Vector2 * center = load_struct_Vector2(L, -3, false);
	float radius = lua_tonumber(L, -2);
	Rectangle * rec = load_struct_Rectangle(L, -1, false);
	bool returnVal = CheckCollisionCircleRec(*center, radius, *rec);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_CheckCollisionPointRec(lua_State *L) {
	Vector2 * point = load_struct_Vector2(L, -2, false);
	Rectangle * rec = load_struct_Rectangle(L, -1, false);
	bool returnVal = CheckCollisionPointRec(*point, *rec);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_CheckCollisionPointCircle(lua_State *L) {
	Vector2 * point = load_struct_Vector2(L, -3, false);
	Vector2 * center = load_struct_Vector2(L, -2, false);
	float radius = lua_tonumber(L, -1);
	bool returnVal = CheckCollisionPointCircle(*point, *center, radius);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_CheckCollisionPointTriangle(lua_State *L) {
	Vector2 * point = load_struct_Vector2(L, -4, false);
	Vector2 * p1 = load_struct_Vector2(L, -3, false);
	Vector2 * p2 = load_struct_Vector2(L, -2, false);
	Vector2 * p3 = load_struct_Vector2(L, -1, false);
	bool returnVal = CheckCollisionPointTriangle(*point, *p1, *p2, *p3);
	lua_pushboolean(L, returnVal);
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
static int l_CheckCollisionPointLine(lua_State *L) {
	Vector2 * point = load_struct_Vector2(L, -4, false);
	Vector2 * p1 = load_struct_Vector2(L, -3, false);
	Vector2 * p2 = load_struct_Vector2(L, -2, false);
	int threshold = lua_tointeger(L, -1);
	bool returnVal = CheckCollisionPointLine(*point, *p1, *p2, threshold);
	lua_pushboolean(L, returnVal);
	return 1;
}
static int l_GetCollisionRec(lua_State *L) {
	Rectangle * rec1 = load_struct_Rectangle(L, -2, false);
	Rectangle * rec2 = load_struct_Rectangle(L, -1, false);
	Rectangle returnVal = GetCollisionRec(*rec1, *rec2);
		
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, "Rectangle");
        lua_getfield(L, -1, "new");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (Rectangle *) lua_touserdata(L, -1);
        *userdata = returnVal;
        
        lua_pop(L, 1); // pop userdata
        ;
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
static int l_rlBegin(lua_State *L) {
	int mode = lua_tointeger(L, -1);
	rlBegin(mode);
	;
	return 1;
}
static int l_rlEnd(lua_State *L) {
	rlEnd();
	;
	return 1;
}
static int l_rlVertex2i(lua_State *L) {
	int x = lua_tointeger(L, -2);
	int y = lua_tointeger(L, -1);
	rlVertex2i(x, y);
	;
	return 1;
}
static int l_rlVertex2f(lua_State *L) {
	float x = lua_tonumber(L, -2);
	float y = lua_tonumber(L, -1);
	rlVertex2f(x, y);
	;
	return 1;
}
static int l_rlVertex3f(lua_State *L) {
	float x = lua_tonumber(L, -3);
	float y = lua_tonumber(L, -2);
	float z = lua_tonumber(L, -1);
	rlVertex3f(x, y, z);
	;
	return 1;
}
static int l_rlTexCoord2f(lua_State *L) {
	float x = lua_tonumber(L, -2);
	float y = lua_tonumber(L, -1);
	rlTexCoord2f(x, y);
	;
	return 1;
}
static int l_rlNormal3f(lua_State *L) {
	float x = lua_tonumber(L, -3);
	float y = lua_tonumber(L, -2);
	float z = lua_tonumber(L, -1);
	rlNormal3f(x, y, z);
	;
	return 1;
}
static int l_rlColor4ub(lua_State *L) {
	int r = lua_tointeger(L, -4);
	int g = lua_tointeger(L, -3);
	int b = lua_tointeger(L, -2);
	int a = lua_tointeger(L, -1);
	rlColor4ub(r, g, b, a);
	;
	return 1;
}
static int l_rlColor3f(lua_State *L) {
	float x = lua_tonumber(L, -3);
	float y = lua_tonumber(L, -2);
	float z = lua_tonumber(L, -1);
	rlColor3f(x, y, z);
	;
	return 1;
}
static int l_rlColor4f(lua_State *L) {
	float x = lua_tonumber(L, -4);
	float y = lua_tonumber(L, -3);
	float z = lua_tonumber(L, -2);
	float w = lua_tonumber(L, -1);
	rlColor4f(x, y, z, w);
	;
	return 1;
}
static int l_rlMatrixMode(lua_State *L) {
	int mode = lua_tointeger(L, -1);
	rlMatrixMode(mode);
	;
	return 1;
}
static int l_rlPushMatrix(lua_State *L) {
	rlPushMatrix();
	;
	return 1;
}
static int l_rlPopMatrix(lua_State *L) {
	rlPopMatrix();
	;
	return 1;
}
static int l_rlLoadIdentity(lua_State *L) {
	rlLoadIdentity();
	;
	return 1;
}
static int l_rlTranslatef(lua_State *L) {
	float x = lua_tonumber(L, -3);
	float y = lua_tonumber(L, -2);
	float z = lua_tonumber(L, -1);
	rlTranslatef(x, y, z);
	;
	return 1;
}
static int l_rlRotatef(lua_State *L) {
	float angle = lua_tonumber(L, -4);
	float x = lua_tonumber(L, -3);
	float y = lua_tonumber(L, -2);
	float z = lua_tonumber(L, -1);
	rlRotatef(angle, x, y, z);
	;
	return 1;
}
static int l_rlScalef(lua_State *L) {
	float x = lua_tonumber(L, -3);
	float y = lua_tonumber(L, -2);
	float z = lua_tonumber(L, -1);
	rlScalef(x, y, z);
	;
	return 1;
}
static int l_rlViewport(lua_State *L) {
	int x = lua_tointeger(L, -4);
	int y = lua_tointeger(L, -3);
	int width = lua_tointeger(L, -2);
	int height = lua_tointeger(L, -1);
	rlViewport(x, y, width, height);
	;
	return 1;
}
void init_raylib_bindings1(lua_State *L) {
	lua_createtable(L, 0, 200);
	lua_createtable(L, 0, 200);
	lua_setfield(L, -2, "@");
	lua_getfield(L, -1, "@");
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
	lua_pushcfunction(L, Vector3_read_x);
	lua_setfield(L, -2, "Vector3_read_x");
	lua_pushcfunction(L, Vector3_write_x);
	lua_setfield(L, -2, "Vector3_write_x");
	lua_pushcfunction(L, Vector3_read_y);
	lua_setfield(L, -2, "Vector3_read_y");
	lua_pushcfunction(L, Vector3_write_y);
	lua_setfield(L, -2, "Vector3_write_y");
	lua_pushcfunction(L, Vector3_read_z);
	lua_setfield(L, -2, "Vector3_read_z");
	lua_pushcfunction(L, Vector3_write_z);
	lua_setfield(L, -2, "Vector3_write_z");
	lua_pushcfunction(L, Vector3_Alloc);
	lua_setfield(L, -2, "Vector3_Alloc");
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
	lua_pushcfunction(L, Camera3D_read_fovy);
	lua_setfield(L, -2, "Camera3D_read_fovy");
	lua_pushcfunction(L, Camera3D_write_fovy);
	lua_setfield(L, -2, "Camera3D_write_fovy");
	lua_pushcfunction(L, Camera3D_read_projection);
	lua_setfield(L, -2, "Camera3D_read_projection");
	lua_pushcfunction(L, Camera3D_write_projection);
	lua_setfield(L, -2, "Camera3D_write_projection");
	lua_pushcfunction(L, Camera3D_Alloc);
	lua_setfield(L, -2, "Camera3D_Alloc");
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
	lua_pushcfunction(L, l_IsKeyPressed);
	lua_setfield(L, -2, "IsKeyPressed");
	lua_pushcfunction(L, l_IsKeyDown);
	lua_setfield(L, -2, "IsKeyDown");
	lua_pushcfunction(L, l_IsKeyReleased);
	lua_setfield(L, -2, "IsKeyReleased");
	lua_pushcfunction(L, l_IsKeyUp);
	lua_setfield(L, -2, "IsKeyUp");
	lua_pushcfunction(L, l_SetExitKey);
	lua_setfield(L, -2, "SetExitKey");
	lua_pushcfunction(L, l_GetKeyPressed);
	lua_setfield(L, -2, "GetKeyPressed");
	lua_pushcfunction(L, l_GetCharPressed);
	lua_setfield(L, -2, "GetCharPressed");
	lua_pushcfunction(L, l_ClearBackground);
	lua_setfield(L, -2, "ClearBackground");
	lua_pushcfunction(L, l_BeginDrawing);
	lua_setfield(L, -2, "BeginDrawing");
	lua_pushcfunction(L, l_EndDrawing);
	lua_setfield(L, -2, "EndDrawing");
	lua_pushcfunction(L, l_BeginMode2D);
	lua_setfield(L, -2, "BeginMode2D");
	lua_pushcfunction(L, l_EndMode2D);
	lua_setfield(L, -2, "EndMode2D");
	lua_pushcfunction(L, l_BeginMode3D);
	lua_setfield(L, -2, "BeginMode3D");
	lua_pushcfunction(L, l_EndMode3D);
	lua_setfield(L, -2, "EndMode3D");
	lua_pushcfunction(L, l_IsMouseButtonPressed);
	lua_setfield(L, -2, "IsMouseButtonPressed");
	lua_pushcfunction(L, l_IsMouseButtonDown);
	lua_setfield(L, -2, "IsMouseButtonDown");
	lua_pushcfunction(L, l_IsMouseButtonReleased);
	lua_setfield(L, -2, "IsMouseButtonReleased");
	lua_pushcfunction(L, l_IsMouseButtonUp);
	lua_setfield(L, -2, "IsMouseButtonUp");
	lua_pushcfunction(L, l_GetMouseX);
	lua_setfield(L, -2, "GetMouseX");
	lua_pushcfunction(L, l_GetMouseY);
	lua_setfield(L, -2, "GetMouseY");
	lua_pushcfunction(L, l_GetMousePosition);
	lua_setfield(L, -2, "GetMousePosition");
	lua_pushcfunction(L, l_GetMouseDelta);
	lua_setfield(L, -2, "GetMouseDelta");
	lua_pushcfunction(L, l_DrawPixel);
	lua_setfield(L, -2, "DrawPixel");
	lua_pushcfunction(L, l_DrawPixelV);
	lua_setfield(L, -2, "DrawPixelV");
	lua_pushcfunction(L, l_DrawLine);
	lua_setfield(L, -2, "DrawLine");
	lua_pushcfunction(L, l_DrawLineV);
	lua_setfield(L, -2, "DrawLineV");
	lua_pushcfunction(L, l_DrawLineEx);
	lua_setfield(L, -2, "DrawLineEx");
	lua_pushcfunction(L, l_DrawLineBezier);
	lua_setfield(L, -2, "DrawLineBezier");
	lua_pushcfunction(L, l_DrawLineBezierQuad);
	lua_setfield(L, -2, "DrawLineBezierQuad");
	lua_pushcfunction(L, l_DrawLineBezierCubic);
	lua_setfield(L, -2, "DrawLineBezierCubic");
	lua_pushcfunction(L, l_DrawLineStrip);
	lua_setfield(L, -2, "DrawLineStrip");
	lua_pushcfunction(L, l_DrawCircle);
	lua_setfield(L, -2, "DrawCircle");
	lua_pushcfunction(L, l_DrawCircleSector);
	lua_setfield(L, -2, "DrawCircleSector");
	lua_pushcfunction(L, l_DrawCircleSectorLines);
	lua_setfield(L, -2, "DrawCircleSectorLines");
	lua_pushcfunction(L, l_DrawCircleGradient);
	lua_setfield(L, -2, "DrawCircleGradient");
	lua_pushcfunction(L, l_DrawCircleV);
	lua_setfield(L, -2, "DrawCircleV");
	lua_pushcfunction(L, l_DrawCircleLines);
	lua_setfield(L, -2, "DrawCircleLines");
	lua_pushcfunction(L, l_DrawEllipse);
	lua_setfield(L, -2, "DrawEllipse");
	lua_pushcfunction(L, l_DrawEllipseLines);
	lua_setfield(L, -2, "DrawEllipseLines");
	lua_pushcfunction(L, l_DrawRing);
	lua_setfield(L, -2, "DrawRing");
	lua_pushcfunction(L, l_DrawRingLines);
	lua_setfield(L, -2, "DrawRingLines");
	lua_pushcfunction(L, l_DrawRectangle);
	lua_setfield(L, -2, "DrawRectangle");
	lua_pushcfunction(L, l_DrawRectangleV);
	lua_setfield(L, -2, "DrawRectangleV");
	lua_pushcfunction(L, l_DrawRectangleRec);
	lua_setfield(L, -2, "DrawRectangleRec");
	lua_pushcfunction(L, l_DrawRectanglePro);
	lua_setfield(L, -2, "DrawRectanglePro");
	lua_pushcfunction(L, l_DrawRectangleGradientV);
	lua_setfield(L, -2, "DrawRectangleGradientV");
	lua_pushcfunction(L, l_DrawRectangleGradientH);
	lua_setfield(L, -2, "DrawRectangleGradientH");
	lua_pushcfunction(L, l_DrawRectangleGradientEx);
	lua_setfield(L, -2, "DrawRectangleGradientEx");
	lua_pushcfunction(L, l_DrawRectangleLines);
	lua_setfield(L, -2, "DrawRectangleLines");
	lua_pushcfunction(L, l_DrawRectangleLinesEx);
	lua_setfield(L, -2, "DrawRectangleLinesEx");
	lua_pushcfunction(L, l_DrawRectangleRounded);
	lua_setfield(L, -2, "DrawRectangleRounded");
	lua_pushcfunction(L, l_DrawRectangleRoundedLines);
	lua_setfield(L, -2, "DrawRectangleRoundedLines");
	lua_pushcfunction(L, l_DrawText);
	lua_setfield(L, -2, "DrawText");
	lua_pushcfunction(L, l_CheckCollisionRecs);
	lua_setfield(L, -2, "CheckCollisionRecs");
	lua_pushcfunction(L, l_CheckCollisionCircles);
	lua_setfield(L, -2, "CheckCollisionCircles");
	lua_pushcfunction(L, l_CheckCollisionCircleRec);
	lua_setfield(L, -2, "CheckCollisionCircleRec");
	lua_pushcfunction(L, l_CheckCollisionPointRec);
	lua_setfield(L, -2, "CheckCollisionPointRec");
	lua_pushcfunction(L, l_CheckCollisionPointCircle);
	lua_setfield(L, -2, "CheckCollisionPointCircle");
	lua_pushcfunction(L, l_CheckCollisionPointTriangle);
	lua_setfield(L, -2, "CheckCollisionPointTriangle");
	lua_pushcfunction(L, l_CheckCollisionLines);
	lua_setfield(L, -2, "CheckCollisionLines");
	lua_pushcfunction(L, l_CheckCollisionPointLine);
	lua_setfield(L, -2, "CheckCollisionPointLine");
	lua_pushcfunction(L, l_GetCollisionRec);
	lua_setfield(L, -2, "GetCollisionRec");
	lua_pushcfunction(L, l_ColorAlpha);
	lua_setfield(L, -2, "ColorAlpha");
	lua_pushcfunction(L, l_GetScreenToWorld2D);
	lua_setfield(L, -2, "GetScreenToWorld2D");
	lua_pushcfunction(L, l_Vector2Distance);
	lua_setfield(L, -2, "Vector2Distance");
	lua_pushcfunction(L, l_Vector2DistanceSqr);
	lua_setfield(L, -2, "Vector2DistanceSqr");
	lua_pushcfunction(L, l_Vector2Add);
	lua_setfield(L, -2, "Vector2Add");
	lua_pushcfunction(L, l_Vector2Scale);
	lua_setfield(L, -2, "Vector2Scale");
	lua_pushcfunction(L, l_rlBegin);
	lua_setfield(L, -2, "rlBegin");
	lua_pushcfunction(L, l_rlEnd);
	lua_setfield(L, -2, "rlEnd");
	lua_pushcfunction(L, l_rlVertex2i);
	lua_setfield(L, -2, "rlVertex2i");
	lua_pushcfunction(L, l_rlVertex2f);
	lua_setfield(L, -2, "rlVertex2f");
	lua_pushcfunction(L, l_rlVertex3f);
	lua_setfield(L, -2, "rlVertex3f");
	lua_pushcfunction(L, l_rlTexCoord2f);
	lua_setfield(L, -2, "rlTexCoord2f");
	lua_pushcfunction(L, l_rlNormal3f);
	lua_setfield(L, -2, "rlNormal3f");
	lua_pushcfunction(L, l_rlColor4ub);
	lua_setfield(L, -2, "rlColor4ub");
	lua_pushcfunction(L, l_rlColor3f);
	lua_setfield(L, -2, "rlColor3f");
	lua_pushcfunction(L, l_rlColor4f);
	lua_setfield(L, -2, "rlColor4f");
	lua_pushcfunction(L, l_rlMatrixMode);
	lua_setfield(L, -2, "rlMatrixMode");
	lua_pushcfunction(L, l_rlPushMatrix);
	lua_setfield(L, -2, "rlPushMatrix");
	lua_pushcfunction(L, l_rlPopMatrix);
	lua_setfield(L, -2, "rlPopMatrix");
	lua_pushcfunction(L, l_rlLoadIdentity);
	lua_setfield(L, -2, "rlLoadIdentity");
	lua_pushcfunction(L, l_rlTranslatef);
	lua_setfield(L, -2, "rlTranslatef");
	lua_pushcfunction(L, l_rlRotatef);
	lua_setfield(L, -2, "rlRotatef");
	lua_pushcfunction(L, l_rlScalef);
	lua_setfield(L, -2, "rlScalef");
	lua_pushcfunction(L, l_rlViewport);
	lua_setfield(L, -2, "rlViewport");
	lua_setglobal(L, "rl");
}

