import {BindInternalClass} from "../Bind";

export abstract class Base {
    // Internal properties

    x: number;
    y: number;
    angle: number;
    index: number;
    active: boolean;
    drawScale: number;
    classID: number;


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

