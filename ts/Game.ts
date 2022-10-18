import {Player} from "./Objects/Player";
import {SpawnEntity} from "./Entity";
import {Planet} from "./Objects/Planet";
import {Base} from "./Objects/Base";
import {NavMapScene} from "./Scenes/NavMapScene";
import {Scene} from "./Scenes/Scene";
import {GameScene} from "./Scenes/GameScene";
import {Global} from "./Global";
import {Galaxy} from "./Galaxy";
import {PlayerController} from "./PlayerController";
import DrawText = rl.DrawText;

class Message {
    time: number;
    message: string;
}

export class Game {

    purpleColor: rl.Color;

    scenes: Array<Scene> = [];

    constructor() {
        Global.game = this;
        Global.player = SpawnEntity(Player);
        Global.galaxy = new Galaxy();
        Global.planet = Global.galaxy.planets[Math.round(Math.random() * Global.galaxy.planets.length)];
        Global.galaxy.ExploreSystem(Global.planet);

        Global.playerController = new PlayerController();

        let planet0: Planet = SpawnEntity(Planet);
        planet0.x = 20;
        planet0.y = 20;

        this.purpleColor = new rl.Color({r: 255, g: 0, b: 128, a: 255});

        this.AddSceneAndFocus(new GameScene());

        this.Message("Game init...", 3.0);

    }

    AddSceneAndFocus(scene: Scene) {
        if(this.scenes.length > 0) {
            this.scenes[this.scenes.length - 1].isFocused = false;
        }

        this.scenes.push(scene);
        scene.isFocused = true;
    }

    OnMouseDown(x: number, y: number, buttons: number) {
        // console.log("OnMouseDown", x,y, buttons);
        for(let s of this.scenes) {
            s.OnMouseDown(x, y, buttons);
        }
    }

    OnMouseUp(x: number, y: number, buttons: number) {
        // console.log("OnMouseUp", x,y, buttons);
        for(let s of this.scenes) {
            s.OnMouseUp(x, y, buttons);
        }
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

        Global.playerController.Update();

        for(let s of this.scenes) {
            s.Update();
        }

        for(let m of this.messages) {
            m.time -= 0.016;
            if(m.time < 0) {
                this.messages = this.messages.filter(value => value != m);
            }
        }
    }

    Draw() {
        for(let s of this.scenes) {
            s.Draw();
        }

        let y = 400;
        for(let i = this.messages.length - 1; i >= 0; i--) {
            let m = this.messages[i];
            DrawText(m.message, 32, y, 20, rl.BLACK);
            y -= 18;
        }
    }

    RemoveScene(param: Scene) {
       this.scenes = this.scenes.filter(value => value != param);

       if(this.scenes.length > 0) {
           this.scenes[this.scenes.length - 1].isFocused = true;
       }
    }



    messages: Array<Message> = [];

    Message(msg:string, time: number) {
        let m = new Message();
        m.message = msg;
        m.time = time;
        this.messages.push(m);
    }
}