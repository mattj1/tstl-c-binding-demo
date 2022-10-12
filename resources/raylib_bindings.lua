return function(____exports)
-- Rectangle
local Rectangle = {}
Rectangle.prototype = {}
Rectangle.read_bindings = {}
Rectangle.write_bindings = {}
Rectangle.read_bindings.x = rl["@"]["Rectangle_read_x"]
Rectangle.write_bindings.x = rl["@"]["Rectangle_write_x"]
Rectangle.read_bindings.y = rl["@"]["Rectangle_read_y"]
Rectangle.write_bindings.y = rl["@"]["Rectangle_write_y"]
Rectangle.read_bindings.width = rl["@"]["Rectangle_read_width"]
Rectangle.write_bindings.width = rl["@"]["Rectangle_write_width"]
Rectangle.read_bindings.height = rl["@"]["Rectangle_read_height"]
Rectangle.write_bindings.height = rl["@"]["Rectangle_write_height"]
Rectangle.mt = {
    	 __index = function(t, k) return Rectangle.read_bindings[k](t) end,
    	 __newindex = function(t, k, v) Rectangle.write_bindings[k](t, v) end
    }

function Rectangle:new(args)
    o = {}
    setmetatable(o, Rectangle.mt)

    d = rl["@"]["Rectangle_Alloc"]()
    rawset(o, "@", d)
    if args then
        for a0, a1 in pairs(args) do
            o[a0] = a1
        end
     end
    return o
end
____exports.Rectangle = Rectangle
-- Color
local Color = {}
Color.prototype = {}
Color.read_bindings = {}
Color.write_bindings = {}
Color.read_bindings.r = rl["@"]["Color_read_r"]
Color.write_bindings.r = rl["@"]["Color_write_r"]
Color.read_bindings.g = rl["@"]["Color_read_g"]
Color.write_bindings.g = rl["@"]["Color_write_g"]
Color.read_bindings.b = rl["@"]["Color_read_b"]
Color.write_bindings.b = rl["@"]["Color_write_b"]
Color.read_bindings.a = rl["@"]["Color_read_a"]
Color.write_bindings.a = rl["@"]["Color_write_a"]
Color.mt = {
    	 __index = function(t, k) return Color.read_bindings[k](t) end,
    	 __newindex = function(t, k, v) Color.write_bindings[k](t, v) end
    }

function Color:new(args)
    o = {}
    setmetatable(o, Color.mt)

    d = rl["@"]["Color_Alloc"]()
    rawset(o, "@", d)
    if args then
        for a0, a1 in pairs(args) do
            o[a0] = a1
        end
     end
    return o
end
____exports.Color = Color
-- Vector2
local Vector2 = {}
Vector2.prototype = {}
Vector2.read_bindings = {}
Vector2.write_bindings = {}
Vector2.read_bindings.x = rl["@"]["Vector2_read_x"]
Vector2.write_bindings.x = rl["@"]["Vector2_write_x"]
Vector2.read_bindings.y = rl["@"]["Vector2_read_y"]
Vector2.write_bindings.y = rl["@"]["Vector2_write_y"]
Vector2.mt = {
    	 __index = function(t, k) return Vector2.read_bindings[k](t) end,
    	 __newindex = function(t, k, v) Vector2.write_bindings[k](t, v) end
    }

function Vector2:new(args)
    o = {}
    setmetatable(o, Vector2.mt)

    d = rl["@"]["Vector2_Alloc"]()
    rawset(o, "@", d)
    if args then
        for a0, a1 in pairs(args) do
            o[a0] = a1
        end
     end
    return o
end
____exports.Vector2 = Vector2
____exports.LIGHTGRAY = Color:new({r = 200, g = 200, b = 200, a = 255})
____exports.BLUE = Color:new({r = 0, g = 0, b = 245, a = 255})
____exports.RAYWHITE = Color:new({r = 245, g = 245, b = 245, a = 255})
____exports.KeyboardKey = {
	KEY_NULL = 0,
	KEY_APOSTROPHE = 39,
	KEY_COMMA = 44,
	KEY_MINUS = 45,
	KEY_PERIOD = 46,
	KEY_SLASH = 47,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_SEVEN = 55,
	KEY_EIGHT = 56,
	KEY_NINE = 57,
	KEY_SEMICOLON = 59,
	KEY_EQUAL = 61,
	KEY_A = 65,
	KEY_B = 66,
	KEY_C = 67,
	KEY_D = 68,
	KEY_E = 69,
	KEY_F = 70,
	KEY_G = 71,
	KEY_H = 72,
	KEY_I = 73,
	KEY_J = 74,
	KEY_K = 75,
	KEY_L = 76,
	KEY_M = 77,
	KEY_N = 78,
	KEY_O = 79,
	KEY_P = 80,
	KEY_Q = 81,
	KEY_R = 82,
	KEY_S = 83,
	KEY_T = 84,
	KEY_U = 85,
	KEY_V = 86,
	KEY_W = 87,
	KEY_X = 88,
	KEY_Y = 89,
	KEY_Z = 90,
	KEY_LEFT_BRACKET = 91,
	KEY_BACKSLASH = 92,
	KEY_RIGHT_BRACKET = 93,
	KEY_GRAVE = 96,
	KEY_SPACE = 32,
	KEY_ESCAPE = 256,
	KEY_ENTER = 257,
	KEY_TAB = 258,
	KEY_BACKSPACE = 259,
	KEY_INSERT = 260,
	KEY_DELETE = 261,
	KEY_RIGHT = 262,
	KEY_LEFT = 263,
	KEY_DOWN = 264,
	KEY_UP = 265,
	KEY_PAGE_UP = 266,
	KEY_PAGE_DOWN = 267,
	KEY_HOME = 268,
	KEY_END = 269,
	KEY_CAPS_LOCK = 280,
	KEY_SCROLL_LOCK = 281,
	KEY_NUM_LOCK = 282,
	KEY_PRINT_SCREEN = 283,
	KEY_PAUSE = 284,
	KEY_F1 = 290,
	KEY_F2 = 291,
	KEY_F3 = 292,
	KEY_F4 = 293,
	KEY_F5 = 294,
	KEY_F6 = 295,
	KEY_F7 = 296,
	KEY_F8 = 297,
	KEY_F9 = 298,
	KEY_F10 = 299,
	KEY_F11 = 300,
	KEY_F12 = 301,
	KEY_LEFT_SHIFT = 340,
	KEY_LEFT_CONTROL = 341,
	KEY_LEFT_ALT = 342,
	KEY_LEFT_SUPER = 343,
	KEY_RIGHT_SHIFT = 344,
	KEY_RIGHT_CONTROL = 345,
	KEY_RIGHT_ALT = 346,
	KEY_RIGHT_SUPER = 347,
	KEY_KB_MENU = 348,
	KEY_KP_0 = 320,
	KEY_KP_1 = 321,
	KEY_KP_2 = 322,
	KEY_KP_3 = 323,
	KEY_KP_4 = 324,
	KEY_KP_5 = 325,
	KEY_KP_6 = 326,
	KEY_KP_7 = 327,
	KEY_KP_8 = 328,
	KEY_KP_9 = 329,
	KEY_KP_DECIMAL = 330,
	KEY_KP_DIVIDE = 331,
	KEY_KP_MULTIPLY = 332,
	KEY_KP_SUBTRACT = 333,
	KEY_KP_ADD = 334,
	KEY_KP_ENTER = 335,
	KEY_KP_EQUAL = 336,
	KEY_BACK = 4,
	KEY_MENU = 82,
	KEY_VOLUME_UP = 24,
	KEY_VOLUME_DOWN = 25,
}
return ____exports
end
