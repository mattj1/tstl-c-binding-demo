import {Base} from "./Base";
import {RegisterClass, SpawnEntity} from "../Entity";
import {Shot} from "./Shot";
import {VectorDrawable} from "../Drawable";
import Vector3 = rl.Vector3;
import {Global} from "../Global";

export class Player extends Base {

    velocity: Vector3 = new Vector3();

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

        let keys = Global.playerController.keys;
        let pc = Global.playerController;

        if ((keys & 0x04) != 0) {
            this.angle += 2;
        }

        if ((keys & 0x08) != 0) {
            // Right pressed
            this.angle -= 2;
        }

        if(this.angle < 0) this.angle += 360;
        if(this.angle > 360) this.angle -= 360;

        if ((keys & 0x01) != 0) {
            this.velocity.x += pc.thrust_fac * .01 * Math.cos(this.angle * Math.PI / 180.0);
            this.velocity.y -= pc.thrust_fac * .01 * Math.sin(this.angle * Math.PI / 180.0);
            // this.y -= 2;
        }

        if (rl.IsKeyDown(264)) {
            // this.y += 2;
        }

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_SPACE)) {
            let shot: Shot = SpawnEntity(Shot);
            if(shot != null) {
                shot.x = this.x;
                shot.y = this.y;
                shot.angle = this.angle;
            }
        }

        this.velocity.x *= pc.drag_fac; //0.98;
        this.velocity.y *= pc.drag_fac; //0.98;

        this.x += this.velocity.x;
        this.y += this.velocity.y;
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