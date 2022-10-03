local ____lualib = require("lualib_bundle")
local __TS__Class = ____lualib.__TS__Class
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["6"] = 3,["7"] = 3,["8"] = 3,["10"] = 16,["11"] = 18,["12"] = 29,["13"] = 32,["14"] = 33,["15"] = 34,["16"] = 35,["18"] = 38,["19"] = 39,["20"] = 39,["21"] = 39,["22"] = 39,["23"] = 39,["25"] = 42,["26"] = 48,["27"] = 29,["28"] = 56,["29"] = 59,["30"] = 61,["31"] = 61,["32"] = 61,["33"] = 61,["34"] = 61,["35"] = 61,["38"] = 65,["39"] = 56,["40"] = 68});
local ____exports = {}
____exports.Base = __TS__Class()
local Base = ____exports.Base
Base.name = "Base"
function Base.prototype.____constructor(self)
    self.foo = "Hello"
end
____exports.Base.prototype.__index = function(t, k)
    local raw_val = rawget(t, k)
    if raw_val ~= nil then
        print("__index: found value with rawget for ", k)
        return raw_val
    end
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
