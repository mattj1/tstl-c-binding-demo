import Vector2 = rl.Vector2;
import {Global} from "./Global";
import Vector3 = rl.Vector3;


export class Planet {
    position: Vector3;

    gridX: number;
    gridY: number;

    active: boolean;

    index: number;

    adj: Array<Planet> = [];

    visible: number;

    constructor() {
        this.position = new Vector3();
        this.visible = 0;
    }
}

export class Galaxy {

    planets: Array<Planet> = [];
    paths: Array<Boolean> = []

    dist(planet0: Planet, planet1: Planet) {
        return Math.sqrt(Math.pow((planet0.position.x - planet1.position.x), 2) + Math.pow((planet0.position.y - planet1.position.y), 2));
    }

    CanAddPath(planet0: Planet, planet1: Planet) : boolean {

        for(let i1 = 0; i1 < this.planets.length; i1++) {
            for (let j1 = 0; j1 < i1; j1++) {

                if (!this.PathExistsIndex(i1, j1))
                    continue;

                let planet3 = this.planets[i1];
                let planet4 = this.planets[j1];

                if (rl.CheckCollisionLines(planet0.position, planet1.position, planet3.position, planet4.position, null)) {
                    return false;
                }
            }
        }

        return true;
    }

    constructor() {
        console.log("Generating Galaxy...");
        let GRID_WIDTH = 20, GRID_HEIGHT = 20;

        for (let y = 0; y < GRID_HEIGHT; y++) {
            for (let x = 0; x < GRID_WIDTH; x++) {
                if (Math.random() > 0.7) {
                    let planet = new Planet();
                    planet.position.x = x * 40 + Math.random() * 40;
                    planet.position.y = y * 40 + Math.random() * 40;
                    planet.gridX = x;
                    planet.gridY = y;
                    planet.active = true;
                    this.planets.push(planet);
                }
            }
        }

        // Remove very close planets

        for (let p of this.planets) {
            if (!p.active) continue;
            for (let p2 of this.planets) {
                if (p == p2)
                    continue;
                if (!p.active) continue;

                if (rl.Vector2DistanceSqr(p.position, p2.position) < 35 * 35){
                    p2.active = false;
                }
            }
        }

        this.planets = this.planets.filter(value => value.active);
        console.log("number of planets: ", this.planets.length);

        for(let i = 0; i < this.planets.length; i++) {
            this.planets[i].index = i;
        }

        // Start by connecting every planet to several nearby planets
        for(let i = 0; i < this.planets.length; i++) {
            let planet0 = this.planets[i];

            let l = this.planets.slice();

            l = l.sort((a, b) => this.dist(a, planet0) - this.dist(b, planet0))

            for(let j = 0; j < 6; j++) {
                let planet1 = l[j];
                if(planet1 == planet0)
                    continue;

                // Check to see if adding this path will overlap existing paths

                if(this.CanAddPath(planet0, planet1)) {
                    this.AddPath(planet0, planet1);
                }
            }
        }

        console.log("Generating Galaxy Done");
    }


    AddPath(planet0: Planet, planet1: Planet) {
        if(planet0 == planet1)
            return;

        let maxIndex = Math.max(planet0.index, planet1.index);
        let minIndex = Math.min(planet0.index, planet1.index);

        this.paths[minIndex * this.planets.length + maxIndex] = true;

        planet0.adj.push(planet1);
        planet1.adj.push(planet0);
    }

    PathExistsIndex(i0: number, i1: number): boolean {
        let maxIndex = Math.max(i0, i1);
        let minIndex = Math.min(i0, i1);

        return (this.paths[minIndex * this.planets.length + maxIndex] == true);
    }

    PathExists(planet0: Planet, planet1: Planet): boolean {
        return this.PathExistsIndex(planet0.index, planet1.index);
    }

    ExploreSystem(planet: Planet) {
        if(planet == null)
            return;

        planet.visible = 2;

        for(let p1 of planet.adj) {
            if(p1.visible == 0)
                p1.visible = 1;
        }
    }
}