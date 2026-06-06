# _SET_PED_COMBAT_RANGE

--- ns: PED --- ## SET_PED_COMBAT_RANGE  // 0x3C606747B23E497B 0x8818A959 void SET_PED_COMBAT_RANGE(Ped ped, int range);  Define the scope within which the ped will engage in combat with the target.  enum eCombatRange { CR_NEAR = 0, // keeps within 5-15m CR_MEDIUM = 1, // keeps within 7-30m CR_FAR = 2, // keeps within 15-40m CR_VERY_FAR = 3 // keeps within 22-45m };  ## Parameters * **ped**: Ped index * **range**: See `eCombatRange` enum.

### Parameters
* Ped ped
* int combatRange

### Return Value
* void

### Notes
* AP Hash: 0x0x8818A959
* Build: 323
* enum eCombatRange // 0xB69160F5
{
	CR_Near,
	CR_Medium,
	CR_Far,
	CR_VeryFar,
	CR_NumRanges
};

