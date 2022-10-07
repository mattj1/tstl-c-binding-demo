import {Base} from "./Base";
import {RegisterClass} from "../Entity";

export class Planet extends Base {
    GetDrawable(): any {
        return _G.resources.shot;
    }

    PostInit(): void {
        this.drawScale = 4;
    }

    Update(): void {

    }
}

RegisterClass(Planet);