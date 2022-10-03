local ____lualib = require("lualib_bundle")
local __TS__Class = ____lualib.__TS__Class
local __TS__ClassExtends = ____lualib.__TS__ClassExtends
local __TS__SourceMapTraceBack = ____lualib.__TS__SourceMapTraceBack
__TS__SourceMapTraceBack(debug.getinfo(1).short_src, {["7"] = 1,["8"] = 1,["9"] = 3,["10"] = 3,["11"] = 3,["12"] = 3,["14"] = 3,["15"] = 6,["16"] = 4,["17"] = 9,["18"] = 10,["19"] = 11,["20"] = 9,["21"] = 14,["22"] = 15,["23"] = 16,["25"] = 20,["26"] = 22,["28"] = 26,["29"] = 27,["30"] = 28,["32"] = 32,["34"] = 14});
local ____exports = {}
local ____Base = require("Objects.Base")
local Base = ____Base.Base
____exports.Player = __TS__Class()
local Player = ____exports.Player
Player.name = "Player"
__TS__ClassExtends(Player, Base)
function Player.prototype.____constructor(self)
    Base.prototype.____constructor(self)
    print("new player")
end
function Player.prototype.PostInit(self)
    self.x = 200
    self.y = 200
end
function Player.prototype.Update(self)
    if IsKeyDown(nil, 263) then
        self.angle = self.angle - 2
    end
    if IsKeyDown(nil, 262) then
        self.angle = self.angle + 2
    end
    if IsKeyDown(nil, 265) then
        self.x = self.x + 2 * math.cos(self.angle * math.pi / 180)
        self.y = self.y + 2 * math.sin(self.angle * math.pi / 180)
    end
    if IsKeyDown(nil, 264) then
    end
end
return ____exports
