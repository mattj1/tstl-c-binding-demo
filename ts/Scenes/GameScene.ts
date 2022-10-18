import {Scene} from "./Scene";
import {Global} from "../Global";
import {NavMapScene} from "./NavMapScene";
import BeginMode3D = rl.BeginMode3D;
import EndMode3D = rl.EndMode3D;
import {VectorSet} from "../Math";




export class GameScene extends Scene {
    camera: rl.Camera3D;

    constructor() {
        super();

        this.camera = new rl.Camera3D();
        this.camera.up = new rl.Vector3({x: 0, y: 0, z: -1.0});
        this.camera.fovy = 45.0;
        this.camera.projection = rl.CameraProjection.CAMERA_PERSPECTIVE;
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
        VectorSet(this.camera.position, Global.player.x, 40.0, Global.player.y);
        VectorSet(this.camera.target, Global.player.x, 0, Global.player.y);

        rl.BeginMode3D(this.camera);

        rl.rlColor3f(rl.LIGHTGRAY.r, rl.LIGHTGRAY.g, rl.LIGHTGRAY.b);
        rl.rlBegin(0x0001); // TODO: Support RL_LINES
        for(let x = -100; x < 100; x+= 10) {
            rl.rlVertex3f(x, 0, -100);
            rl.rlVertex3f(x, 0, 100);

            rl.rlVertex3f(-100, 0,  x);
            rl.rlVertex3f(100, 0, x);
        }
        rl.rlEnd();

        AllEntities((o: Base) => {
            rl.rlPushMatrix();
            rl.rlTranslatef(o.x, 0, o.y);
            rl.rlScalef(o.drawScale, o.drawScale, o.drawScale);
            rl.rlRotatef(o.angle, 0, 1, 0);
            DrawVectorArt(o.GetDrawable());
            rl.rlPopMatrix();

            rl.rlPushMatrix();

            rl.rlTranslatef(o.x - 2, 0, o.y - 2);
            rl.rlScalef(0.1, 0.1, 0.1);
            rl.rlRotatef(o.angle, 0, 1, 0);
            rl.rlRotatef(90, 1, 0, 0);
            //printf("%d\n", entity->classID);
            if (o.classID == 3) {
                rl.DrawText("Planet", 0, 0, 16, rl.BLACK);
            }
//                DrawRectanglePro(Rectangle{entity->x, entity->y, 20, 20}, Vector2{10, 10}, entity->angle, RED);
            rl.rlPopMatrix();
            return false;
        });

        rl.EndMode3D();

        if(this.isFocused) {
            rl.DrawText(`Player pos: ${Global.player.x} ${Global.player.y}`, 64, 64, 10, rl.BLUE);
            rl.DrawText(`N - open navigation map`, 64, 96, 20, rl.BLUE);
        }
        // if(Global.playerController.isHyperspace) {
        //     rl.DrawText(`Hyperspace in ${Global.playerController.hyperspaceTime}...`, 64, 96, 24, rl.BLUE);
        // }
    }

    OnMouseWheel(wheel: number) {
    }
}