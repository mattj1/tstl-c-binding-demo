import {Game} from "./Game";

// // @ts-ignore
// console.log(instance.index, instance.__data, instance.x)
// // @ts-ignore
// console.log(instance2.index, instance2.__data, instance2.x)

export function InitGame() {
    console.log("--- InitGame ---");
    return new Game();
}
