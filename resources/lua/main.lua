local ____lualib = require("lualib_bundle")
local __TS__New = ____lualib.__TS__New
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["6"] = 1,["7"] = 1,["8"] = 3,["9"] = 4,["10"] = 5,["11"] = 3});
local ____exports = {}
local ____Game = require("Game")
local Game = ____Game.Game
function ____exports.InitGame(self)
    print("--- InitGame ---")
    return __TS__New(Game)
end
return ____exports
