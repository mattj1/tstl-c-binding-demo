import Rectangle = rl.Rectangle;

export class NavMap {
    r: Rectangle;
    r2: Rectangle;

    constructor() {
        this.r = new Rectangle({x:0, y:0, width:64, height:64});
        this.r2 = new Rectangle({x:40, y:40, width:64, height:64});
    }

    Update() {

    }

    Draw() {
        rl.DrawText(`*** Nav map ***`, 128, 128, 24, rl.BLUE);

        rl.DrawRectangle(this.r.x, this.r.y, this.r.width, this.r.height, rl.ColorAlpha(rl.LIGHTGRAY, 0.5))
        rl.DrawRectangleLinesEx(this.r, 3, rl.BLUE)
    }
}