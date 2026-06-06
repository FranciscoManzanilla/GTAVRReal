# _SHOOT_SINGLE_BULLET_BETWEEN_COORDS_IGNORE_ENTITY_NEW

--- ns: MISC aliases: ["0xBFE5756E7407064A","_SHOOT_SINGLE_BULLET_BETWEEN_COORDS_WITH_EXTRA_PARAMS"] --- ## SHOOT_SINGLE_BULLET_BETWEEN_COORDS_IGNORE_ENTITY_NEW  // 0xBFE5756E7407064A 0xCCDC33CC void SHOOT_SINGLE_BULLET_BETWEEN_COORDS_IGNORE_ENTITY_NEW(float x1, float y1, float z1, float x2, float y2, float z2, int damage, BOOL p7, Hash weaponHash, Ped ownerPed, BOOL isAudible, BOOL isInvisible, float speed, Entity entity, BOOL p14, BOOL p15, BOOL p16, BOOL p17);  NativeDB Added Parameter 19: Any p18 NativeDB Added Parameter 20: Any p19 NativeDB Added Parameter 21: Any p20  ## Parameters * **x1**: * **y1**: * **z1**: * **x2**: * **y2**: * **z2**: * **damage**: * **p7**: * **weaponHash**: * **ownerPed**: * **isAudible**: * **isInvisible**: * **speed**: * **entity**: * **p14**: * **p15**: * **p16**: * **p17**:

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* int damage
* BOOL p7
* Hash weaponHash
* Ped ownerPed
* BOOL isAudible
* BOOL isInvisible
* float speed
* Entity entity
* BOOL p14
* BOOL p15
* Entity targetEntity
* BOOL p17
* Any p18
* Any p19
* Any p20

### Return Value
* void

### Notes
* AP Hash: 0x0xCCDC33CC
* Build: 323
* entity - entity to ignore
targetEntity - entity to home in on, if the weapon hash provided supports homing

