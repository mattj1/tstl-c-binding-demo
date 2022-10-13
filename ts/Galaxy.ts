export class Planet {
    x: number;
    y: number;

    gridX: number;
    gridY: number;

    active: boolean;
}

export class Galaxy {

    planets: Array<Planet> = [];

    constructor() {
        let grid = [];
        let GRID_WIDTH = 20;

        for(let y = 0; y < 20; y++) {
            for(let x = 0; x < GRID_WIDTH; x++) {
                if(Math.random() > 0.7) {
                    let planet = new Planet();
                    planet.x = x * 40 + Math.random() * 40;
                    planet.y = y * 40 + Math.random() * 40;
                    planet.gridX = x;
                    planet.gridY = y;
                    planet.active = true;
                    this.planets.push(planet);

                    grid[y * GRID_WIDTH + x] = planet;
                }
            }
        }

        for(let p of this.planets) {
            if(!p.active) continue;
            for(let p2 of this.planets){
                if(p == p2)
                    continue;
                if(!p.active) continue;

                if(Math.abs(p.x - p2.x) < 35 && Math.abs(p.y - p2.y) < 35) {
                    console.log("delete", p2);
                    p2.active = false;
                    grid[p2.y * GRID_WIDTH + p2.x] = undefined;
                }
            }
        }

        this.planets = this.planets.filter(value => value.active);
    }
}