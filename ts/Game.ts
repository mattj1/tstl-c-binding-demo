import {Player} from "./Objects/Player";
import {SpawnEntity} from "./Entity";
import {Planet} from "./Objects/Planet";
import {Base} from "./Objects/Base";
import {NavMap} from "./NavMap";

let player: Player;

export class Game {

    purpleColor: rl.Color;

    navMap: NavMap;

    constructor() {
        console.log("New Game")

        player = SpawnEntity(Player);

        let planet0: Planet = SpawnEntity(Planet);
        planet0.x = 20;
        planet0.y = 20;

        this.purpleColor = new rl.Color({r: 255, g: 0, b: 128, a: 255});

        this.navMap = new NavMap();
    }

    Update() {
        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_H)) {
            console.log("Begin hyperspace");
        }

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_N)) {
            console.log("Nav panel");
        }

        // console.log("Game.Update()");

        // AllEntities((e: Base) => {
        //     // @ts-ignore
        //     console.log("AllEntities entity", e.index, e.classID, e.drawable);
        //     return false;
        // })
    }

    Draw() {
        rl.DrawText(`Player pos: ${player.x} ${player.y}`, 64, 64, 24, rl.BLUE);

        this.navMap.Draw();
    }
}