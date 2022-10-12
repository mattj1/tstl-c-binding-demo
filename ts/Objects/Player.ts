import {Base} from "./Base";
import {RegisterClass, SpawnEntity} from "../Entity";
import {Shot} from "./Shot";
import {VectorDrawable} from "../Drawable";

export class Player extends Base {
    constructor() {
        super();
        console.log("new player")

        this.drawable = new VectorDrawable(_G.resources.player_ship);
    }

    PostInit() {
        this.x = 0;
        this.y = 0;
    }

    Update() {
        if (rl.IsKeyDown(263)) {
            this.angle += 2;
        }

        if (rl.IsKeyDown(262)) {
            // Right pressed
            this.angle -= 2;
        }

        if (rl.IsKeyDown(rl.KeyboardKey.KEY_UP)) {
            this.x += .2 * Math.cos(this.angle * Math.PI / 180.0);
            this.y -= .2 * Math.sin(this.angle * Math.PI / 180.0);
            // this.y -= 2;
        }

        if (rl.IsKeyDown(264)) {
            // this.y += 2;
        }

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_SPACE)) {
            let shot: Shot = SpawnEntity(Shot);
            if(shot) {
                shot.x = this.x;
                shot.y = this.y;
                shot.angle = this.angle;
            }
        }
    }

    public ReadFromSnapshot(msgbuf: any) {
        super.ReadFromSnapshot(msgbuf);
        console.log("Player.ReadFromSnapshot", msgbuf);

        let val = MSG_ReadInt(msgbuf);
        console.log("got val: ", val);
    }

    public GetDrawable(): any {
       return _G.resources.player_ship;
    }
}

RegisterClass(Player);