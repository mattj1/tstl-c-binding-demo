import Rectangle = rl.Rectangle;
import {Scene} from "./Scene";
import {Global} from "../Global";
import Camera2D = rl.Camera2D;
import Vector2 = rl.Vector2;



export class NavMapScene extends Scene {
    r: Rectangle;
    r2: Rectangle;
    camera: Camera2D;

    constructor() {
        super();
        this.r = new Rectangle({x:0, y:0, width:64, height:64});
        this.r2 = new Rectangle({x:40, y:40, width:64, height:64});
        this.camera = new Camera2D();
        this.camera.zoom = 0.75;
        this.camera.offset.x = -128;
    }

    Update() {

    }

    Draw() {
        rl.DrawText(`*** Nav map ***`, 128, 128, 24, rl.BLUE);

        rl.DrawRectangle(this.r.x, this.r.y, this.r.width, this.r.height, rl.ColorAlpha(rl.LIGHTGRAY, 0.5))
        rl.DrawRectangleLinesEx(this.r, 3, rl.BLUE)

        rl.BeginMode2D(this.camera);
        for(let planet of Global.galaxy.planets) {
            if(planet.visible == 2) {
                for(let p1 of planet.adj) {
                    rl.DrawLine(planet.position.x, planet.position.y, p1.position.x, p1.position.y, rl.BLUE);
                }

                rl.DrawCircle(planet.position.x, planet.position.y, 10, rl.BLUE);

            }

            if(planet.visible == 1) {
                rl.DrawCircle(planet.position.x, planet.position.y, 10, rl.LIGHTGRAY);
            }
        }

        // for(let i = 0; i < Global.galaxy.planets.length; i++) {
        //     for (let j = 0; j < Global.galaxy.planets.length; j++) {
        //         let planet0 = Global.galaxy.planets[i];
        //         let planet1 = Global.galaxy.planets[j];
        //         if (Global.galaxy.PathExists(planet0, planet1)) {
        //             // rl.DrawLine(planet0.position.x, planet0.position.y, planet1.position.x, planet1.position.y, rl.BLUE);
        //         }
        //     }
        // }
        rl.EndMode2D();
    }

    OnMouseDown(x: number, y: number, buttons: number) {

    }

    OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number) {
        if (rl.IsMouseButtonDown(rl.MouseButton.MOUSE_BUTTON_LEFT))
        {
            let delta = rl.GetMouseDelta();
            delta = rl.Vector2Scale(delta, -1.0/this.camera.zoom);

            this.camera.target = rl.Vector2Add(this.camera.target, delta);
        }
    }

    OnMouseUp(x: number, y: number, buttons: number) {
    }

    OnMouseWheel(wheel: number) {
        // Get the world point that is under the mouse
        let mouseWorldPos = rl.GetScreenToWorld2D(rl.GetMousePosition(), this.camera);

        // Set the offset to where the mouse is
        this.camera.offset = rl.GetMousePosition();

        // Set the target to match, so that the camera maps the world space point
        // under the cursor to the screen space point under the cursor at any zoom
        this.camera.target = mouseWorldPos;

        // Zoom increment
        let zoomIncrement = 0.125;

        this.camera.zoom += (wheel*zoomIncrement);
        if (this.camera.zoom < zoomIncrement) this.camera.zoom = zoomIncrement;
    }
}