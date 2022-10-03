local ____lualib = require("lualib_bundle")
local __TS__Class = ____lualib.__TS__Class
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["6"] = 3,["7"] = 3,["8"] = 3,["10"] = 16,["11"] = 18,["12"] = 29,["13"] = 32,["14"] = 33,["15"] = 33,["16"] = 33,["17"] = 33,["18"] = 33,["20"] = 36,["21"] = 37,["22"] = 29,["23"] = 41,["24"] = 44,["25"] = 46,["26"] = 46,["27"] = 46,["28"] = 46,["29"] = 46,["30"] = 46,["33"] = 50,["34"] = 41,["35"] = 53});
local ____exports = {}
____exports.Base = __TS__Class()
local Base = ____exports.Base
Base.name = "Base"
function Base.prototype.____constructor(self)
    self.foo = "Hello"
end
____exports.Base.prototype.__index = function(t, k)
    if isInternalProp(nil, k) then
        return getProp(
            nil,
            rawget(t, "__data"),
            k
        )
    end
    local mt = getmetatable(t)
    return mt[k]
end
____exports.Base.prototype.__newindex = function(t, k, v)
    if isInternalProp(nil, k) then
        setProp(
            nil,
            rawget(t, "__data"),
            k,
            v
        )
        return
    end
    rawset(t, k, v)
end
print("End of Base.ts")
return ____exports
