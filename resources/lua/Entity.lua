local ____lualib = require("lualib_bundle")
local __TS__New = ____lualib.__TS__New
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["6"] = 2,["7"] = 7,["8"] = 8,["9"] = 9,["10"] = 10,["11"] = 12,["12"] = 2});
local ____exports = {}
function ____exports.SpawnEntity(self, clz)
    local instance = __TS__New(clz)
    print("SpawnEntity instance", clz.name, instance)
    AssignEntity(nil, instance)
    instance:PostInit()
    return instance
end
return ____exports
