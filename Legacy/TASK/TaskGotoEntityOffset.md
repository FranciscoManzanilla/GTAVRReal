# _TASK_GOTO_ENTITY_OFFSET

--- ns: TASK --- ## TASK_GOTO_ENTITY_OFFSET  // 0xE39B4FF4FDEBDE27 0x1A17A85E void TASK_GOTO_ENTITY_OFFSET(Ped ped, Entity entity, int duration, float seekRadius, float seekAngleDeg, float moveBlendRatio, int gotoEntityOffsetFlags);  Instructs the ped to go to the entity with the given offset.  enum eSeekEntityOffsetFlags { ESEEK_OFFSET_ORIENTATES_WITH_ENTITY = 1, ESEEK_KEEP_TO_PAVEMENTS = 2 };  ## Parameters * **ped**: The ped handle * **entity**: The target entity handle * **duration**: The duration in seconds or -1 for forever * **seekRadius**: How many meters the destination is from the entity * **seekAngleDeg**: The angle the destination is from the entity * **moveBlendRatio**: The move blend ratio (speed) * **gotoEntityOffsetFlags**: The goto entity offset flags

### Parameters
* Ped ped
* Entity entity
* int time
* float seekRadius
* float seekAngleDeg
* float moveBlendRatio
* int gotoEntityOffsetFlags

### Return Value
* void

### Notes
* AP Hash: 0x0x1A17A85E
* Build: 323
* enum ESEEK_ENTITY_OFFSET_FLAGS
{
	ESEEK_OFFSET_ORIENTATES_WITH_ENTITY = 0x01,
	ESEEK_KEEP_TO_PAVEMENTS = 0x02
};

