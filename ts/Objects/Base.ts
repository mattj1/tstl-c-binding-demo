

export abstract class Base {
    // Internal properties

    // @ts-ignore;
    x: number;

    // @ts-ignore;
    y: number;

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

    let raw_val = rawget(t, k)
    if (raw_val != null) {
        console.log("__index: found value with rawget for ", k)
        return raw_val;
    }

    if (isInternalProp(k)) {
        return getProp(rawget(t, "__data"), k)
    }

    let mt: any = getmetatable(t)
    // for key,value in pairs(mt) do
    //     -- print("found member " .. key);
    // end

    // print("Base.prototype.__index: returning from metatable: " .. k)
    return mt[k];

    // --raw_val = rawget(rawget(Base, "prototype"), k)
    // --print("__index: Returning something else for key ".. k .. ": " .. tostring(raw_val))
    // --return raw_val;
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
