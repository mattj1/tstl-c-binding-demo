local ____lualib = require("lualib_bundle")
local __TS__Class = ____lualib.__TS__Class
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["6"] = 1,["7"] = 1,["8"] = 2,["9"] = 2,["10"] = 4,["11"] = 6,["12"] = 6,["13"] = 6,["15"] = 8,["16"] = 10,["17"] = 7,["18"] = 13,["19"] = 13});
local ____exports = {}
local ____Player = require("Objects.Player")
local Player = ____Player.Player
local ____Entity = require("Entity")
local SpawnEntity = ____Entity.SpawnEntity
local player
____exports.Game = __TS__Class()
local Game = ____exports.Game
Game.name = "Game"
function Game.prototype.____constructor(self)
    print("New Game")
    player = SpawnEntity(nil, Player)
end
function Game.prototype.Update(self)
end
return ____exports
