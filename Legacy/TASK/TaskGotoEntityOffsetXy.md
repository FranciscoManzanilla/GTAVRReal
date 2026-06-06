# _TASK_GOTO_ENTITY_OFFSET_XY

--- ns: TASK --- ## TASK_GOTO_ENTITY_OFFSET_XY  // 0x338E7EF52B6095A9 0xBC1E3D0A void TASK_GOTO_ENTITY_OFFSET_XY(Ped ped, Entity entity, int duration, float targetRadius, float offsetX, float offsetY, float moveBlendRatio, cs_type(BOOL) int gotoEntityOffsetFlags);  Instructs the ped to go to the entity with the given offset.  ## Parameters * **ped**: The ped handle * **entity**: The target entity handle * **duration**: The duration in seconds or -1 for forever * **targetRadius**: How far away the ped needs to be from the target entity before it starts moving * **offsetX**: The X offset * **offsetY**: The Y offset * **moveBlendRatio**: The move blend ratio (speed) * **gotoEntityOffsetFlags**: The goto entity offset flags (see [`TASK_GOTO_ENTITY_OFFSET`](#_0xE39B4FF4FDEBDE27))

### Parameters
* Ped ped
* Entity entity
* int duration
* float targetRadius
* float offsetX
* float offsetY
* float moveBlendRatio
* int gotoEntityOffsetFlags

### Return Value
* void

### Notes
* AP Hash: 0x0xBC1E3D0A
* Build: 323

