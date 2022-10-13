export abstract class Scene {
    active: boolean;

    constructor() {
        this.active = true;
    }

    abstract OnMouseDown(x: number, y: number, buttons: number);

    abstract OnMouseUp(x: number, y: number, buttons: number);

    abstract OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number);

    abstract OnMouseWheel(wheel: number) ;

    abstract Update();

    abstract Draw();
}