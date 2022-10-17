import {Player} from "./Objects/Player";
import {Galaxy, Planet} from "./Galaxy";
import {PlayerController} from "./PlayerController";
import {Game} from "./Game";

export class Global {
    static player: Player;
    static galaxy: Galaxy;

    // Current Planet
    static planet: Planet;

    static playerController: PlayerController;

    static game: Game;
}
