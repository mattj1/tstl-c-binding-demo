import {Player} from "./Objects/Player";
import {SpawnEntity} from "./Entity";

let player: Player;

export class Game {

    constructor() {
        console.log("New Game")

        player = SpawnEntity(Player);
    }

    Update() {
        // console.log("Game.Update()");
    }
}