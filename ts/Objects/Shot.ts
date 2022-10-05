import {Base} from "./Base";

export class Shot extends Base {
    life: number;

    constructor() {
        super();

        this.life = 0;
    }

    PostInit() {
        this.drawScale = 0.2;

    }

    Update() {
        this.life += 0.0166;

        if(this.life > 2.0) {
            this.active = false;
            return;
        }

        let velocity = 0.4;
        let angle = this.angle * Math.PI / 180.0
        this.x += velocity * Math.cos(angle);
        this.y -= velocity * Math.sin(angle);


    }

    GetDrawable(): any {
        return _G.resources.shot;
    }
}