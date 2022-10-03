

export abstract class Base {
    // Internal properties

    // @ts-ignore;
    x: number;

    // @ts-ignore;
    y: number;

    // @ts-ignore
    angle: number;

    // @ts-ignore;
    index: number;

    // TS properties
    foo: string = "Hello";

    constructor() {
        // console.log("Base Constructor")
        //this.x = 123;
    }

    abstract Update(): void;

    abstract PostInit(): void;
}

// @ts-ignore
Base.prototype.__index = function(this: void, t, k): any {
    // console.log("Base.prototype.__index ", t, k)

    if (isInternalProp(k)) {
        return getProp(rawget(t, "__data"), k)
    }

    let mt: any = getmetatable(t)
    return mt[k];
}

// @ts-ignore
Base.prototype.__newindex = function(this: void, t, k: string, v: any): void {
    // console.log(`Base.prototype.__newindex Table: ${tostring(t)} Key: ${tostring(k)} Value: ${tostring(v)}`)
    // debug.traceback("test");
    if(isInternalProp(k)){
        // console.log("should set internal prop ", k , "=" , tostring(v))
        setProp(rawget(t, "__data"), k, v);
        return;
    }

    rawset(t, k, v)
}

console.log("End of Base.ts");
