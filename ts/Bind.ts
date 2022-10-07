type ClassRef = abstract new (...args: any[]) => any;

export function BindInternalClass(this: void,
                              clz: ClassRef,
                              isInternalProp: IsInternalPropFunc,
                              getProp: GetPropFunc,
                              setProp: SetPropFunc) {

    clz.prototype.__index = function(this: void, t, k): any {
        // console.log("Base.prototype.__index ", t, k)
        if (isInternalProp(k)) {
            return getProp(rawget(t, "__data"), k)
        }

        let mt: any = getmetatable(t)
        return mt[k];
    }

    clz.prototype.__newindex = function(this: void, t, k: string, v: any): void {
        // console.log(`Base.prototype.__newindex Table: ${tostring(t)} Key: ${tostring(k)} Value: ${tostring(v)}`)
        // debug.traceback("test");
        if(isInternalProp(k)){
            // console.log("should set internal prop ", k , "=" , tostring(v))
            setProp(rawget(t, "__data"), k, v);
            return;
        }

        rawset(t, k, v)
    }
}
