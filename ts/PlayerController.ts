import {Planet} from "./Galaxy";
import {Global} from "./Global";

export class PlayerController {
    destinationPlanet: Planet;

    hyperspaceTime: number = 0;

    hyperSpaceState: any;

    keys: number = 0;

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
    }

    private SetHyperSpaceState(state: any) {
        this.hyperSpaceState = state;
    }

    private HyperspaceSlow() {
        console.log("slow...");

        if (Math.abs(Global.player.velocity.x) < 0.1 && Math.abs(Global.player.velocity.y) < 0.1) {
            this.hyperspaceTime = 1;
            this.SetHyperSpaceState(this.HyperspaceTurn);

        }
    }

    private HyperspaceTurn() {
        console.log("turn...");
        this.hyperspaceTime -= 0.016;
        if (this.hyperspaceTime <= 0) {
            this.hyperspaceTime = 2;
            this.SetHyperSpaceState(this.HyperspaceWarp);
        }
    }

    private HyperspaceWarp() {
        console.log("warping!");
        this.hyperspaceTime -= 0.016;
        if (this.hyperspaceTime <= 0) {
            this.hyperSpaceState = null;
            let vx = this.destinationPlanet.position.x - Global.planet.position.x;
            let vy = this.destinationPlanet.position.y - Global.planet.position.y;

            Global.planet = this.destinationPlanet;
            Global.galaxy.ExploreSystem(this.destinationPlanet);

            Global.player.x = 0;
            Global.player.y = 0;
            Global.player.velocity.x = vx * .007;
            Global.player.velocity.y = vy * .007;

            this.SetHyperSpaceState(null);
        }
    }

    Update() {
        if (this.hyperSpaceState) {
            this.hyperSpaceState();
        }
    }


}