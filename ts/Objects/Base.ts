import {BindInternalClass} from "../Bind";
import {Drawable} from "../Drawable";

export abstract class Base {
    // Internal properties

    // @ts-ignore
    x: number;
    // @ts-ignore
    y: number;
    // @ts-ignore
    angle: number;
    // @ts-ignore
    index: number;
    // @ts-ignore
    active: boolean;
    // @ts-ignore
    drawScale: number;
    // @ts-ignore
    classID: number;

    drawable: Drawable = null;

    // TS properties
    foo: string = "Hello";

    constructor() {
        // console.log("Base Constructor")
        //this.x = 123;
    }

    abstract Update(): void;

    abstract PostInit(): void;

    public ReadFromSnapshot(msgbuf: any) {
    }

    public GetDrawable(): any {
        return null;
    }
}

Internal_Init_Entity_Base(BindInternalClass, Base);

