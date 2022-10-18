import Vector3 = rl.Vector3;

export function VectorCopy(a: rl.Vector3, b: rl.Vector3) {
    b.x = a.x;
    b.y = a.y;
    b.z = a.z;
}

export function VectorSet(v: rl.Vector3, x: number, y: number, z: number) {
    v.x = x;
    v.y = y;
    v.z = z;
}

export function VectorSubtract(a: Vector3, b: Vector3, c: Vector3) {
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
}