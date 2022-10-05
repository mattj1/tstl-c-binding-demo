import {Game} from "./Game";

_G.InitGame = function() {
    console.log("--- InitGame ---");
    return new Game();
}

_G.runstuff = function() {
    console.log("--- runstuff ---");
    for(let k in _G.package.loaded) {
        console.log(k);
    }

    console.log(_G.package.loaded["Objects.Base"])
}
