# _TASK_MOVE_NETWORK_BY_NAME

--- ns: TASK aliases: ["0x2D537BA194896636","_TASK_MOVE_NETWORK"] --- ## TASK_MOVE_NETWORK_BY_NAME  // 0x2D537BA194896636 0x6F5D215F void TASK_MOVE_NETWORK_BY_NAME(Ped ped, char* task, float multiplier, BOOL p3, char* animDict, int flags);  Example: TASK::TASK_MOVE_NETWORK_BY_NAME(PLAYER::PLAYER_PED_ID(), "arm_wrestling_sweep_paired_a_rev3", 0.0f, true, "mini@arm_wrestling", 0);  ## Parameters * **ped**: * **task**: * **multiplier**: * **p3**: * **animDict**: * **flags**:

### Parameters
* Ped ped
* const char* task
* float multiplier
* BOOL allowOverrideCloneUpdate
* const char* animDict
* int flags

### Return Value
* void

### Notes
* AP Hash: 0x0x6F5D215F
* Build: 323
* Example:
TASK::TASK_MOVE_NETWORK_BY_NAME(PLAYER::PLAYER_PED_ID(), "arm_wrestling_sweep_paired_a_rev3", 0.0f, true, "mini@arm_wrestling", 0);

