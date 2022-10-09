// let structs: {[key: string]: StructDef} = {};
let structs: Record<string, StructDef> = {};
let globalFunctions: Array<Func> = [];

abstract class TypeDef {
    name: string;

    protected constructor(name: string) {
        this.name = name;
    }

    abstract generateLuaTo(funcName: string, parmName: string, stackPos: number): string;
    abstract generateLuaPush(parm: ParmType): string;
}

class ParmType {
    name: string;
    typeDef: TypeDef;

    constructor(name: string, typeDef: TypeDef) {
        this.name = name;
        this.typeDef = typeDef
    }

    generateLuaGetParm(funcName: string, stackPos: number): string {
        return this.typeDef.generateLuaTo(funcName, this.name, stackPos);
    }
}

abstract class SimpleTypeDef extends TypeDef {

}

class IntType extends SimpleTypeDef {

    constructor() {
        super("int");
    }

    generateLuaTo(funcName: string, parmName: string, stackPos: number) {
        return `\tauto ${parmName} = lua_tointeger(L, ${stackPos});`
    }

    generateLuaPush(parm: ParmType): string {
        return `lua_pushinteger(L, ${parm.name})`;
    }
}

class FloatType extends SimpleTypeDef {
    constructor() {
        super("float");
    }

    generateLuaTo(funcName: string, parmName: string, stackPos: number) {
        return `\tauto ${parmName} = lua_tonumber(L, ${stackPos});`
    }

    generateLuaPush(parm: ParmType): string {
        return `lua_pushnumber(L, ${parm.name})`;
    }
}

class StructDef extends TypeDef {
    members: ParmType[];

    constructor(name: string) {
        super(name);
        this.members = [];
    }

    Int(name: string): StructDef {
        this.members.push(new ParmType(name, new IntType()));
        return this;
    }

    Float(name: string): StructDef {
        this.members.push(new ParmType(name, new FloatType()));
        return this;
    }

    generateLuaTo(funcName: string, parmName: string, stackPos: number) {
        let s = `\tif(!lua_isuserdata(L, ${stackPos}) {\n`;
        s += `\t\tprintf("${funcName}: Error: ${parmName} is not userdata\\n")\n`;
        s += `\t\t return 0;"\n`;
        s += `\t}\n`;

        s += `\tauto ${parmName} = *(${this.name} *) lua.touserdata(L, ${stackPos});\n`;

        return s;
    }

    generateLuaPush(parm: ParmType): string {
        // e.g. Image variableName = Image_New()
        // Need to call
        let s = `\t
        lua_getglobal(L, "rl");
        lua_getfield(L, -1, \"${this.name}\");
        lua_getfield(L, -1, \"new\");
        lua_pushvalue(L, -2);
        lua_call(L, 1, 1);
        
        lua_pushstring(L, "@");
        lua_rawget(L, -2);
        
        auto userdata = (${this.name} *) lua_touserdata(L, -1);
        *val = ${parm.name};
        
        lua_pop(L, 1); // pop userdata
        `;
        return s;
    }
}

class PointerType extends TypeDef {

    typeDef: TypeDef;

    constructor(name: string, typeDef: TypeDef) {
        super(name);

        this.typeDef = typeDef;
    }

    generateLuaTo(funcName: string, parmName: string, stackPos: number): string {
        return "";
    }

    generateLuaPush(parm: ParmType): string {
        // e.g. Image variableName = Image_New()
        // Need to call
        let s = `\tNOT IMPLEMENTED`;
        return s;
    }
}

class Func {
    name: string;

    parms: ParmType[];
    returnType: TypeDef;

    constructor(name: string) {
        this.name = name;
        this.parms = [];
    }

    Parm(typeDef: TypeDef, name: string): Func {
        this.parms.push(new ParmType(name, typeDef));
        return this;
    }

    IntParm(name: string) {
        return this.Parm(new IntType(), name);
    }

    Return(returnType: TypeDef): Func {
        this.returnType = returnType;
        return this;
    }
}

function DefStruct(name: string): StructDef {
    let s = new StructDef(name);
    structs[name] = s;
    return s;
}

function DefGlobalFunction(name: string): Func {
    let s = new Func(name);
    globalFunctions.push(s);
    return s;
}

function Run() {
    console.log(`____exports = {}`);
    for (let s of Object.values(structs)) {
        console.log("-- ", s.name);
        console.log(`${s.name} = {}`);
        console.log(`${s.name}.prototype = {}`);
        console.log(`${s.name}.read_bindings = {}`);
        console.log(`${s.name}.write_bindings = {}`);
        for (let m of s.members) {
            console.log(`${s.name}.read_bindings.${m.name} = function(t) return rl["@"]["${s.name}_read_${m.name}"](rawget(t, "@")) end`);
            console.log(`${s.name}.write_bindings.${m.name} = function(t, v) return rl["@"]["${s.name}_write_${m.name}"](rawget(t, "@"), v) end`);
        }

        console.log(`${s.name}.mt = {
    \t __index = function(t, k) return ${s.name}.read_bindings[k](t) end,
    \t __newindex = function(t, k, v) ${s.name}.write_bindings[k](t, v) end
    }`);


        console.log(`
function ${s.name}:new(o)
    o = o or {}
    setmetatable(o, ${s.name}.mt)

    d = rl["@"]["${s.name}_Alloc"]()
    rawset(o, "@", d)
    return o
end
    `);
        console.log(`____exports.${s.name} = ${s.name};`)
    }

    for (let func of globalFunctions) {
        console.log(`static int l_${func.name}(lua_State *L) {`);
        let parm_count = func.parms.length;
        let args = [];


        for (let parm_index in func.parms) {
            let parm = func.parms[parm_index];

            let stackPos = -parm_count + parseInt(parm_index);

            let s = parm.generateLuaGetParm(func.name, stackPos);
            console.log(s);

            args.push(`${parm.name}`);
        }

        let callStr = "\t";

        if(func.returnType) {
            callStr += `auto returnVal = `;
        }

        callStr += `${func.name}(${args.join(', ')});`;

        console.log(callStr);

        if(func.returnType) {
            let returnParm = new ParmType("returnVal", func.returnType);
            console.log("\t" + func.returnType.generateLuaPush(returnParm));
            console.log(`\treturn 1;`);
        } else {
            console.log(`\treturn 0;`);
        }
        console.log(`}`);

        /* static int Rectangle_read_y(lua_State *L) {

        if (!lua_isuserdata(L, -1)) {
            printf("Rectangle_read_y: Error: is not userdata\n");
            return 0;
        }

        auto *rectangle = (Rectangle *) lua_touserdata(L, -1);

        lua_pushnumber(L, rectangle->y);
        return 1;
    }
    */
    }
}


// DefStruct("Rectangle")
//     .Int("x")
//     .Int("y")
//     .Int("w")
//     .Int("h");
//

// let Color = DefStruct("Color")
//     .Int("r")
//     .Int("g")
//     .Int("b")
//     .Int("a");
//
let Vector2 = DefStruct("Vector2")
    .Float("x")
    .Float("y");
//
// // DrawRectangleV(Vector2 position, Vector2 size, Color color);
// DefGlobalFunction("DrawRectangleV")
//     .Parm(Vector2, "position")
//     .Parm(Vector2, "size")
//     .Parm(Color, "color");
//
// DefGlobalFunction("DrawRectangleV")
//     .Parm(Vector2, "position")
//     .Parm(Vector2, "size")
//     .Parm(Color, "color")
//     .IntParm("foo");

// RLAPI int GetRandomValue(int min, int max);
DefGlobalFunction("GetRandomValue")
    .IntParm("min")
    .IntParm("max")
    .Return(new IntType());

DefGlobalFunction("MakeAVector")
    .IntParm("foo")
    .Return(Vector2);

// console.log(process.argv);

Run();
