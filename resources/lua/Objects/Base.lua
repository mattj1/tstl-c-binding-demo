local ____lualib = require("lualib_bundle")
local __TS__Class = ____lualib.__TS__Class
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["6"] = 3,["7"] = 3,["8"] = 3,["10"] = 19,["11"] = 21,["12"] = 32,["13"] = 35,["14"] = 36,["15"] = 36,["16"] = 36,["17"] = 36,["18"] = 36,["20"] = 39,["21"] = 40,["22"] = 32,["23"] = 44,["24"] = 47,["25"] = 49,["26"] = 49,["27"] = 49,["28"] = 49,["29"] = 49,["30"] = 49,["33"] = 53,["34"] = 44,["35"] = 56});
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
