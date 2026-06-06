# _TASK_RAPPEL_FROM_HELI

--- ns: TASK --- ## TASK_RAPPEL_FROM_HELI  // 0x09693B0312F91649 0x2C7ADB93 void TASK_RAPPEL_FROM_HELI(Ped ped, cs_type(int) float unused);  Only appears twice in the scripts. TASK::TASK_RAPPEL_FROM_HELI(PLAYER::PLAYER_PED_ID(), 0x41200000); TASK::TASK_RAPPEL_FROM_HELI(a_0, 0x41200000);  ## Parameters * **ped**: * **unused**:

### Parameters
* Ped ped
* float minHeightAboveGround

### Return Value
* void

### Notes
* AP Hash: 0x0x2C7ADB93
* Build: 323
* minHeightAboveGround: the minimum height above ground the heli must be at before the ped can start rappelling

Only appears twice in the scripts.

TASK::TASK_RAPPEL_FROM_HELI(PLAYER::PLAYER_PED_ID(), 10.0f);
TASK::TASK_RAPPEL_FROM_HELI(a_0, 10.0f);

