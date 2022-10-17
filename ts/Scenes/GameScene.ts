import {Scene} from "./Scene";
import {Global} from "../Global";
import {NavMapScene} from "./NavMapScene";

export class GameScene extends Scene {

    camera: Camera3D;
    constructor() {
        super();

        camera = new Camera3D();
    }

    OnMouseDown(x: number, y: number, buttons: number) {
    }

    OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number) {
    }

    OnMouseUp(x: number, y: number, buttons: number) {
    }

    Update() {
        Global.playerController.Update();

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_N)) {
            let navMapScene = new NavMapScene();
            Global.game.AddSceneAndFocus(navMapScene);
        }
    }

    Draw() {

        AllEntities(o => {

            return false;
        });


        if(this.isFocused) {
            rl.DrawText(`Player pos: ${Global.player.x} ${Global.player.y}`, 64, 64, 12, rl.BLUE);
            rl.DrawText(`N - open navigation map`, 64, 96, 18, rl.BLUE);
        }
        // if(Global.playerController.isHyperspace) {
        //     rl.DrawText(`Hyperspace in ${Global.playerController.hyperspaceTime}...`, 64, 96, 24, rl.BLUE);
        // }
    }

    OnMouseWheel(wheel: number) {
    }
}