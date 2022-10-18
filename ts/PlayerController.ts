import {Galaxy, Planet} from "./Galaxy";
import {Global} from "./Global";
import Vector3 = rl.Vector3;
import {VectorSubtract} from "./Math";

export class PlayerController {
    destinationPlanet: Planet;

    hyperspaceTime: number = 0;

    hyperSpaceState: any;

    keys: number = 0;

    angle_turn: number = 0;
    thrust_fac: number = 1;
    drag_fac: number = 0.98;

    SetDestinationPlanet(planet: Planet) {
        if (planet == null) {
            console.log("No planet selected");
            return;
        }

        if (this.hyperSpaceState) {
            console.log("Already in hyperspace!")
            return;
        }

        this.destinationPlanet = planet;
        this.hyperSpaceState = this.HyperspaceSlow;
        Global.game.Message(`Beginning warp to star system ${this.destinationPlanet.index}`, 2);
    }

    private SetHyperSpaceState(state: any) {
        this.hyperSpaceState = state;
    }

    private HyperspaceSlow() {
        if (Math.abs(Global.player.velocity.x) < 0.1 && Math.abs(Global.player.velocity.y) < 0.1) {
            this.hyperspaceTime = 1;
            this.SetHyperSpaceState(this.HyperspaceTurn);

        }
    }

    private HyperspaceTurn() {

        let v = new Vector3();
        VectorSubtract(this.destinationPlanet.position, Global.planet.position, v);
        let a0 = Math.atan2(-v.y, v.x) * (180/Math.PI);
        // if(a0 < 0) a0 += 360;

        let a1 = Global.player.angle;
        // console.log(`dest ${v.x} ${-v.y} dest angle: ${a0}, player angle: ${a1}`);

        let ap = a0 - a1;
        if(ap <= -180) {
            this.angle_turn = ap + 360;
        } else if(ap <= 180) {
            this.angle_turn = ap;
        } else {
            this.angle_turn = ap - 360;
        }

        if(Math.abs(this.angle_turn) < 2) {
            this.SetHyperSpaceState(this.HyperspaceWarp);
            this.hyperspaceTime = 3;
            this.thrust_fac = 3;
            this.drag_fac = 1;
            Global.game.Message(`Activating warp drive...`, 2);
        }
    }

    private HyperspaceWarp() {
        this.hyperspaceTime -= 0.016;
        if (this.hyperspaceTime <= 0) {
            this.thrust_fac = 1;
            this.drag_fac = 0.98;
            this.hyperSpaceState = null;
            let vx = this.destinationPlanet.position.x - Global.planet.position.x;
            let vy = this.destinationPlanet.position.y - Global.planet.position.y;

            Global.planet = this.destinationPlanet;
            Global.galaxy.ExploreSystem(this.destinationPlanet);

            Global.player.x = 0;
            Global.player.y = 0;
            Global.player.velocity.x = vx * .009;
            Global.player.velocity.y = vy * .009;

            this.SetHyperSpaceState(null);

            Global.game.Message(`Arrived at star system ${Global.planet.index}`, 2);
        }
    }

    Update() {
        if (this.hyperSpaceState) {
            this.hyperSpaceState();
        }
        this.keys = 0;

        if(rl.IsKeyDown(rl.KeyboardKey.KEY_UP)) {
            this.keys |= 0x01;
        }

        if (rl.IsKeyDown(rl.KeyboardKey.KEY_LEFT)) {
            this.keys |= 0x04;
        }

        if (rl.IsKeyDown(rl.KeyboardKey.KEY_RIGHT)) {
            this.keys |= 0x08;
        }

        if(this.hyperSpaceState == this.HyperspaceTurn) {
            if(this.angle_turn > 0) {
                this.keys |= 0x04;
            } else {
                this.keys |= 0x08;
            }
        }

        if(this.hyperSpaceState == this.HyperspaceWarp) {
            this.keys &= ~(0x04 | 0x08);

            this.keys |= 0x01;
        }
    }
}