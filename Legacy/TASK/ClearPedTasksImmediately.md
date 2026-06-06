# _CLEAR_PED_TASKS_IMMEDIATELY

--- ns: TASK --- ## CLEAR_PED_TASKS_IMMEDIATELY  // 0xAAA34F8A7CB32098 0xBC045625 void CLEAR_PED_TASKS_IMMEDIATELY(Ped ped);  Immediately stops the pedestrian from whatever it's doing. The difference between this and [CLEAR_PED_TASKS](#_0xE1EF3C1216AFF2CD) is that this one teleports the ped but does not change the position of the ped.  ## Parameters * **ped**: Ped id.

### Parameters
* Ped ped

### Return Value
* void

### Notes
* AP Hash: 0x0xBC045625
* Build: 323
* Immediately stops the pedestrian from whatever it's doing. They stop fighting, animations, etc. they forget what they were doing.

