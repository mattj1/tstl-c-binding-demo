import Vector2 = rl.Vector2;

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

declare function MSG_ReadInt(msgbuf: any): number;

declare function Internal_Init_Entity_Base(registerClassFunc: RegisterClassFunc, clz: any): void;

declare abstract class Base{
    x: number;
    y: number;
    angle: number;
    index: number;
    active: boolean;
    drawScale: number;
    classID: number;

    public GetDrawable(): any;
}

/** @noSelf **/
type AllEntitiesCallback = (this: void, o: Base) => boolean

/** @noSelf **/
declare function AllEntities(callback: AllEntitiesCallback);

declare function EntityForSlot(slot: number): Base;

declare function DrawVectorArt(art: any): void;

declare function DrawSurroundingRectangle(pt: Vector2, width: number, height: number, color: rl.Color);