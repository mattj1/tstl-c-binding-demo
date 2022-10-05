type IsInternalPropFunc = (k: string) => boolean;
type GetPropFunc = (k: string, userdata: any) => any;
type SetPropFunc = (userdata: any, k: string, v: any) => void;

type RegisterClassFunc = (this: void,
                          clz: any,
                          isInternalProp: IsInternalPropFunc,
                          getPropFunc: GetPropFunc,
                          setPropFunc: SetPropFunc) => void;

// declare function isInternalProp(k: string) : boolean;
// declare function getProp(k: string, userdata: any): any;
// declare function setProp(userdata: any, k: string, v: any): void;

declare function AssignEntity(instance: any): void;

declare function IsKeyDown(key: any): boolean;
declare function IsKeyPressed(key: any): boolean;

declare function MSG_ReadInt(msgbuf: any): number;


declare function Internal_Init_Entity_Base(registerClassFunc: RegisterClassFunc, clz: any): void;