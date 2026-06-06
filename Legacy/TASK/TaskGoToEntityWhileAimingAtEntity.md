# _TASK_GO_TO_ENTITY_WHILE_AIMING_AT_ENTITY

--- ns: TASK --- ## TASK_GO_TO_ENTITY_WHILE_AIMING_AT_ENTITY  // 0x97465886D35210E9 0x68E36B7A void TASK_GO_TO_ENTITY_WHILE_AIMING_AT_ENTITY(Ped ped, Entity entityToWalkTo, Entity entityToAimAt, float speed, BOOL shootatEntity, float p5, float p6, BOOL p7, BOOL p8, Hash firingPattern);  shootatEntity: If true, peds will shoot at Entity till it is dead. If false, peds will just walk till they reach the entity and will cease shooting.  ## Parameters * **ped**: * **entityToWalkTo**: * **entityToAimAt**: * **speed**: * **shootatEntity**: * **p5**: * **p6**: * **p7**: * **p8**: * **firingPattern**:

### Parameters
* Ped ped
* Entity entityToWalkTo
* Entity entityToAimAt
* float speed
* BOOL shootatEntity
* float targetRadius
* float slowDistance
* BOOL useNavMesh
* BOOL instantBlendToAim
* Hash firingPattern

### Return Value
* void

### Notes
* AP Hash: 0x0x68E36B7A
* Build: 323
* shootatEntity:
If true, peds will shoot at Entity till it is dead.
If false, peds will just walk till they reach the entity and will cease shooting.

