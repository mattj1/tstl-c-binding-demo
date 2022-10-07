import {Player} from "./Objects/Player";
import {SpawnEntity} from "./Entity";
import {Planet} from "./Objects/Planet";

let player: Player;

export class Game {

    constructor() {
        console.log("New Game")

        player = SpawnEntity(Player);

        let planet0: Planet = SpawnEntity(Planet);
        planet0.x = 20;
        planet0.y = 20;

    }

    Update() {
        // console.log("Game.Update()");
    }
}