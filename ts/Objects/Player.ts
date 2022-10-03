import {Base} from "./Base";

export class Player extends Base {
    constructor() {
        super();
        console.log("new player")
    }

    PostInit() {
        this.x = 200;
        this.y = 200;
    }

    Update() {
        if (IsKeyDown(263)) {
            this.angle -= 2;
            // this.x -= 2;
        }

        if (IsKeyDown(262)) {
            // Right pressed
            this.angle += 2;
            // this.x += 2;
        }

        if (IsKeyDown(265)) {
            this.x += 2 * Math.cos(this.angle * Math.PI / 180.0);
            this.y += 2 * Math.sin(this.angle * Math.PI / 180.0);
            // this.y -= 2;
        }

        if (IsKeyDown(264)) {
            // this.y += 2;
        }
    }
}