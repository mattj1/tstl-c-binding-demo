import Rectangle = rl.Rectangle;
import {Scene} from "./Scene";
import {Global} from "../Global";
import Camera2D = rl.Camera2D;
import Vector2 = rl.Vector2;
import {Galaxy, Planet} from "../Galaxy";



export class NavMapScene extends Scene {
    r: Rectangle;
    r2: Rectangle;
    camera: Camera2D;

    selectedPlanet: Planet = null;

    constructor() {
        super();
        this.r = new Rectangle({x:0, y:0, width:800, height:600});
        this.r2 = new Rectangle({x:40, y:40, width:64, height:64});
        this.camera = new Camera2D();
        this.camera.zoom = 0.75;
        this.camera.offset.x = -128;
    }

    Update() {
        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_A)) {
            if(this.selectedPlanet != null) {

                Global.playerController.SetDestinationPlanet(this.selectedPlanet);
                this.CloseNavMap();
            }
        }

        if(rl.IsKeyPressed(rl.KeyboardKey.KEY_Q)) {
           this.CloseNavMap();
        }
    }

    CloseNavMap() {
        Global.game.RemoveScene(this);
    }

    Draw() {

        rl.DrawRectangle(this.r.x, this.r.y, this.r.width, this.r.height, rl.ColorAlpha(rl.BLACK, 0.7))
        rl.DrawText(`*** Nav map ***`, 64, 64, 20, rl.RAYWHITE);
        rl.DrawText(`A - Warp to star system`, 64, 96, 20, rl.RAYWHITE);
        rl.DrawText(`Q - Exit map`, 64, 128, 20, rl.RAYWHITE);

        // rl.DrawRectangleLinesEx(this.r, 3, rl.BLUE)

        rl.BeginMode2D(this.camera);
        for(let planet of Global.galaxy.planets) {
            if(planet.visible == 2) {
                for(let p1 of planet.adj) {
                    rl.DrawLineV(planet.position, p1.position, rl.BLUE);
                }

                rl.DrawCircleV(planet.position, 8, rl.BLUE);
            }

            if(planet.visible == 1) {
                rl.DrawCircleV(planet.position, 8, rl.LIGHTGRAY);
            }
        }

        let showSelectedPlanet = this.selectedPlanet;
        if(showSelectedPlanet == null) {
            showSelectedPlanet = Global.planet;
        }
        DrawSurroundingRectangle(showSelectedPlanet.position, 40, 40, rl.RAYWHITE);

        rl.DrawCircleSectorLines(Global.planet.position, 20, 0, 360, 20, rl.BLUE);
        rl.EndMode2D();
    }

    OnMouseDown(x: number, y: number, buttons: number) {
        if(rl.IsMouseButtonPressed(rl.MouseButton.MOUSE_BUTTON_LEFT)) {
            let mouseWorldPos = rl.GetScreenToWorld2D(rl.GetMousePosition(), this.camera);

            for(let p of Global.galaxy.planets) {
                if(p.visible == 0)
                    continue;

                if(rl.Vector2DistanceSqr(p.position, mouseWorldPos) < 20 * 20) {
                    this.selectedPlanet = p;
                    break;
                }
            }
        }
    }

    OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number) {
        if (rl.IsMouseButtonDown(rl.MouseButton.MOUSE_BUTTON_RIGHT))
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