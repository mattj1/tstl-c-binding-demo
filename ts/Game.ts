import {Player} from "./Objects/Player";
import {SpawnEntity} from "./Entity";
import {Planet} from "./Objects/Planet";
import {Base} from "./Objects/Base";
import {NavMapScene} from "./Scenes/NavMapScene";
import {Scene} from "./Scenes/Scene";
import {GameScene} from "./Scenes/GameScene";
import {Global} from "./Global";
import {Galaxy} from "./Galaxy";

export class Game {

    purpleColor: rl.Color;

    navMapScene: NavMapScene;
    gameScene: GameScene;

    scenes: Array<Scene> = [];

    constructor() {
        console.log("New Game")

        Global.player = SpawnEntity(Player);
        Global.galaxy = new Galaxy();

        let planet0: Planet = SpawnEntity(Planet);
        planet0.x = 20;
        planet0.y = 20;

        this.purpleColor = new rl.Color({r: 255, g: 0, b: 128, a: 255});

        this.gameScene = new GameScene();
        this.navMapScene = new NavMapScene();

        this.scenes.push(this.gameScene);
        this.scenes.push(this.navMapScene);
    }

    OnMouseDown(x: number, y: number, buttons: number) {
        // console.log("OnMouseDown", x,y, buttons);
    }

    OnMouseUp(x: number, y: number, buttons: number) {
        // console.log("OnMouseUp", x,y, buttons);
    }

    OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number) {
        // console.log("OnMouseMove ", x, y, dx, dy, buttons);

        for(let s of this.scenes) {
            s.OnMouseMove(x, y, dx, dy, buttons);
        }
    }

    OnMouseWheel(wheel: number) {
        for(let s of this.scenes) {
            s.OnMouseWheel(wheel);
        }
    }

    Update() {
        for(let s of this.scenes) {
            s.Update();
        }

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_H)) {
            console.log("Begin hyperspace");
        }

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_N)) {
            console.log("Nav panel");
        }

        // console.log("Game.Update()");

        // AllEntities((e: Base) => {
        //     // @ts-ignore
        //     console.log("AllEntities entity", e.index, e.classID, e.drawable);
        //     return false;
        // })
    }

    Draw() {
        for(let s of this.scenes) {
            s.Draw();
        }
    }
}