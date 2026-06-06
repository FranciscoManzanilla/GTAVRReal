# _TASK_GOTO_ENTITY_AIMING

--- ns: TASK --- ## TASK_GOTO_ENTITY_AIMING  // 0xA9DA48FAB8A76C12 0xF1C493CF void TASK_GOTO_ENTITY_AIMING(Ped ped, Entity target, float distanceToStopAt, float StartAimingDist);  eg TASK::TASK_GOTO_ENTITY_AIMING(v_2, PLAYER::PLAYER_PED_ID(), 5.0, 25.0); ped = Ped you want to perform this task. target = the Entity they should aim at. distanceToStopAt = distance from the target, where the ped should stop to aim. StartAimingDist = distance where the ped should start to aim.  ## Parameters * **ped**: * **target**: * **distanceToStopAt**: * **StartAimingDist**:

### Parameters
* Ped ped
* Entity target
* float distanceToStopAt
* float StartAimingDist

### Return Value
* void

### Notes
* AP Hash: 0x0xF1C493CF
* Build: 323
* eg

 TASK::TASK_GOTO_ENTITY_AIMING(v_2, PLAYER::PLAYER_PED_ID(), 5.0, 25.0);

ped = Ped you want to perform this task.
target = the Entity they should aim at.
distanceToStopAt = distance from the target, where the ped should stop to aim.
StartAimingDist = distance where the ped should start to aim.

