# _SET_ENTITY_LOD_DIST

--- ns: ENTITY --- ## SET_ENTITY_LOD_DIST  // 0x5927F96A78577363 0xD7ACC7AD void SET_ENTITY_LOD_DIST(Entity entity, int value);  LOD distance can be 0 to 0xFFFF (higher values will result in 0xFFFF) as it is actually stored as a 16-bit value (aka uint16_t).  ## Parameters * **entity**: * **value**:

### Parameters
* Entity entity
* int value

### Return Value
* void

### Notes
* AP Hash: 0x0xD7ACC7AD
* Build: 323
* LOD distance can be 0 to 0xFFFF (higher values will result in 0xFFFF) as it is actually stored as a 16-bit value (aka uint16_t).

