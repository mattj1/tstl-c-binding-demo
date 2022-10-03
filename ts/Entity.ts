
export function SpawnEntity<T>(clz: any): T {
    // TODO: Entity available?

    let instance = new clz();
    console.log("SpawnEntity instance", clz.name, instance);
    AssignEntity(instance);
    instance.PostInit();

    return instance;
}
