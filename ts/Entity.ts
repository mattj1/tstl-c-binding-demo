export function SpawnEntity<T>(clz: any): T {
    // TODO: Entity available?

    let instance = new clz();
    // console.log("SpawnEntity instance", clz.name, instance);
    AssignEntity(instance);

    let data = rawget(instance, "__data");
    if (data) {
        instance.PostInit();

        return instance;
    }
    return null;
}
