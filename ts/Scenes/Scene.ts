export abstract class Scene {
    active: boolean;

    constructor() {
        this.active = true;
    }

    abstract OnMouseDown(x: number, y: number, buttons: number): void;

    abstract OnMouseUp(x: number, y: number, buttons: number): void;

    abstract OnMouseMove(x: number, y: number, dx: number, dy: number, buttons: number): void;

    abstract OnMouseWheel(wheel: number): void;

    abstract Update(): void;

    abstract Draw(): void;
}