local ____exports = {}

Rectangle = {}
Rectangle.prototype = {}
Rectangle.read_bindings = {}
Rectangle.write_bindings = {}
Rectangle.read_bindings.x = function(t) return rl["@"]["Rectangle_read_x"](rawget(t, "@")) end
Rectangle.read_bindings.y = function(t) return rl["@"]["Rectangle_read_y"](rawget(t, "@")) end
Rectangle.read_bindings.w = function(t) return rl["@"]["Rectangle_read_w"](rawget(t, "@")) end
Rectangle.read_bindings.h = function(t) return rl["@"]["Rectangle_read_h"](rawget(t, "@")) end



-- Rectangle.read_bindings = {
--         y = function(t)
--             print("read_bindings y", t)

--             return Rectangle_read_y(rawget(t, "@"))
--             return rl["@"][1](rawget(t, "@"))
--             return rl["@"]["Rectangle_read_y"](rawget(t, "@"))
--         end
-- }

Rectangle.write_bindings = {
        y = function(t, v)
--             print("write_bindings y", t, v)
--             Rectangle_set_y(rawget(t, "@"), v)
--             return rl["@"][2](rawget(t, "@"), v)
                return rl["@"]["Rectangle_set_y"](rawget(t, "@"), v)
        end
}

Rectangle.mt = {
    __index = function(t, k)
    --      print("__index ", t, k)
        return Rectangle.read_bindings[k](t)
    end,
    __newindex = function(t, k, v)
    --     print("__newindex ", t, k, v)
        Rectangle.write_bindings[k](t, v)
    end
}

function Rectangle:new(o)
    o = o or {}
    setmetatable(o, Rectangle.mt)
    d = rl["@"]["Rectangle_Alloc"]()
    --print(d)
    rawset(o, "@", d)
    return o
end

____exports.Rectangle = Rectangle;

--  Vector2
Vector2 = {}
Vector2.prototype = {}
Vector2.read_bindings = {}
Vector2.write_bindings = {}
Vector2.read_bindings.x = function(t) return rl["@"]["Vector2_read_x"](rawget(t, "@")) end
Vector2.write_bindings.x = function(t, v) return rl["@"]["Vector2_write_x"](rawget(t, "@"), v) end
Vector2.read_bindings.y = function(t) return rl["@"]["Vector2_read_y"](rawget(t, "@")) end
Vector2.write_bindings.y = function(t, v) return rl["@"]["Vector2_write_y"](rawget(t, "@"), v) end
Vector2.mt = {
         __index = function(t, k) return Vector2.read_bindings[k](t) end,
         __newindex = function(t, k, v) Vector2.write_bindings[k](t, v) end
    }

function Vector2:new(o)
    o = o or {}
    setmetatable(o, Vector2.mt)

    d = rl["@"]["Vector2_Alloc"]()
    rawset(o, "@", d)
    print("new Vector2 ", o)
    return o
end

____exports.Vector2 = Vector2;




rawset(____exports, "@", {})
print("____exports:", ____exports)
return ____exports
