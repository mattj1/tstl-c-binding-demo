import {Base} from "./Base";
import {SpawnEntity} from "../Entity";
import {Shot} from "./Shot";

export class Player extends Base {
    constructor() {
        super();
        console.log("new player")
    }

    PostInit() {
        this.x = 0;
        this.y = 0;
    }

    Update() {
        if (IsKeyDown(263)) {
            this.angle += 2;
        }

        if (IsKeyDown(262)) {
            // Right pressed
            this.angle -= 2;
        }

        if (IsKeyDown(265)) {
            this.x += .2 * Math.cos(this.angle * Math.PI / 180.0);
            this.y -= .2 * Math.sin(this.angle * Math.PI / 180.0);
            // this.y -= 2;
        }

        if (IsKeyDown(264)) {
            // this.y += 2;
        }

        if(IsKeyPressed(32)) {
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