# _IS_PED_IN_COMBAT

--- ns: PED --- ## IS_PED_IN_COMBAT  // 0x4859F1FC66A6278E 0xFE027CB5 BOOL IS_PED_IN_COMBAT(Ped ped, Ped target);  Examines whether the ped is engaged in combat; when given a target ped index, it confirms if the ped is actively fighting the specified target, returning true if engaged and false if not.  ## Parameters * **ped**: Ped index. * **target**:  ## Return value

### Parameters
* Ped ped
* Ped target

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xFE027CB5
* Build: 323
* Checks to see if ped and target are in combat with eachother. Only goes one-way: if target is engaged in combat with ped but ped has not yet reacted, the function will return false until ped starts fighting back.

p1 is usually 0 in the scripts because it gets the ped id during the task sequence. For instance: PED::IS_PED_IN_COMBAT(l_42E[4/*14*/], PLAYER::PLAYER_PED_ID()) // armenian2.ct4: 43794

