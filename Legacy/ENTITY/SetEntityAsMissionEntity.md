# _SET_ENTITY_AS_MISSION_ENTITY

--- ns: ENTITY --- ## SET_ENTITY_AS_MISSION_ENTITY  // 0xAD738C3085FE7E11 0x5D1F9E0F void SET_ENTITY_AS_MISSION_ENTITY(Entity entity, BOOL scriptHostObject, BOOL bGrabFromOtherScript);  Assigns an existing entity to be owned by the current script. If the entity was not owned by a script yet, this also means the entity will remain persistent until released.  Note that this is not needed right after creating an entity as a script-created entity will automatically be assigned.  ## Parameters * **entity**: An entity handle. * **scriptHostObject**: Whether or not to assign script info to this entity, if set to false the entity will only be protected from despawning locally. * **bGrabFromOtherScript**: Changes the entity so it's owned by the current script if the entity is already a mission entity. This will only work on entities the machine has control of (non-remote entities).

### Parameters
* Entity entity
* BOOL p1
* BOOL p2

### Return Value
* void

### Notes
* AP Hash: 0x0x5D1F9E0F
* Build: 323
* Makes the specified entity (ped, vehicle or object) persistent. Persistent entities will not automatically be removed by the engine.

p1 has no effect when either its on or off 
maybe a quick disassembly will tell us what it does

p2 has no effect when either its on or off 
maybe a quick disassembly will tell us what it does

