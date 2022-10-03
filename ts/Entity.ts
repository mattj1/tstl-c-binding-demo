
export function SpawnEntity<T>(clz: any): T {
    // console.log("SpawnEntity");

    // TODO: Entity available?

    let instance = new clz();
    console.log("SpawnEntity instance", clz.name, instance);
    AssignEntity(instance);
    instance.PostInit();

    return instance;
}
