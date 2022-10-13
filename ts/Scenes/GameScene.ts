import {Scene} from "./Scene";
import {Global} from "../Global";

export class GameScene extends Scene {

    constructor() {
        super();
    }

    OnMouseDown(x: number, y: number, buttons: number) {
    }

    OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number) {
    }

    OnMouseUp(x: number, y: number, buttons: number) {
    }

    Update() {

    }

    Draw() {
        rl.DrawText(`Player pos: ${Global.player.x} ${Global.player.y}`, 64, 64, 24, rl.BLUE);
    }

    OnMouseWheel(wheel: number) {
    }
}