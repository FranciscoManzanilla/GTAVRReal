# _SET_PED_COMBAT_MOVEMENT

--- ns: PED --- ## SET_PED_COMBAT_MOVEMENT  // 0x4D9CA1009AFBD057 0x12E62F9E void SET_PED_COMBAT_MOVEMENT(Ped ped, int combatMovement);  0 - Stationary (Will just stand in place) 1 - Defensive (Will try to find cover and very likely to blind fire) 2 - Offensive (Will attempt to charge at enemy but take cover as well) 3 - Suicidal Offensive (Will try to flank enemy in a suicidal attack)  ## Parameters * **ped**: * **combatMovement**:

### Parameters
* Ped ped
* int combatMovement

### Return Value
* void

### Notes
* AP Hash: 0x0x12E62F9E
* Build: 323
* enum eCombatMovement // 0x4F456B61
{
	CM_Stationary,
	CM_Defensive,
	CM_WillAdvance,
	CM_WillRetreat
};

