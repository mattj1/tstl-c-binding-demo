export function SpawnEntity<T>(clz: any): T {
    // TODO: Entity available?

    let instance = new clz();
    // console.log("SpawnEntity instance", clz.name, instance);
    AssignEntity(instance);
    instance.classID = clz.classID;

    let data = rawget(instance, "__data");
    if (data) {
        instance.PostInit();

        return instance;
    }
    return null;
}

let classID = 1;

export function RegisterClass(clz: any) {
    print("RegisterClass: ", clz.name, classID);
    clz.classID = classID;
    classID += 1;
}