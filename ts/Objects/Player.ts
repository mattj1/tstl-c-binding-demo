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
            this.x -= 2;
        }

        if (IsKeyDown(262)) {
            this.x += 2;
        }

        if (IsKeyDown(265)) {
            this.y -= 2;
        }

        if (IsKeyDown(264)) {
            this.y += 2;
        }
    }
}