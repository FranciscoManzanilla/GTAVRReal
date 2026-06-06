# _IS_PED_ARMED

--- ns: WEAPON --- ## IS_PED_ARMED  // 0x475768A975D5AD17 0x0BFC892C BOOL IS_PED_ARMED(Ped ped, int typeFlags);  Checks if the ped is currently equipped with a weapon matching a bit specified using a bitwise-or in typeFlags.  | Bit value | Effect            | |-----------|-------------------| | 1         | Melee weapons     | | 2         | Explosive weapons | | 4         | Any other weapons |  Not specifying any bit will lead to the native *always* returning 'false', and for example specifying '4 | 2' will check for any weapon except fists and melee weapons.  ## Parameters * **ped**: The ped to check armed state on. * **typeFlags**: Type flags to check.  ## Return value Whether or not the ped is currently equipped with any weapon matching typeFlags.

### Parameters
* Ped ped
* int typeFlags

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x0BFC892C
* Build: 323
* Checks if the ped is currently equipped with a weapon matching a bit specified using a bitwise-or in typeFlags.

Type flag bit values:
1 = Melee weapons
2 = Explosive weapons
4 = Any other weapons

Not specifying any bit will lead to the native *always* returning 'false', and for example specifying '4 | 2' will check for any weapon except fists and melee weapons.
7 returns true if you are equipped with any weapon except your fists.
6 returns true if you are equipped with any weapon except melee weapons.
5 returns true if you are equipped with any weapon except the Explosives weapon group.
4 returns true if you are equipped with any weapon except Explosives weapon group AND melee weapons.
3 returns true if you are equipped with either Explosives or Melee weapons (the exact opposite of 4).
2 returns true only if you are equipped with any weapon from the Explosives weapon group.
1 returns true only if you are equipped with any Melee weapon.
0 never returns true.

Note: When I say "Explosives weapon group", it does not include the Jerry can and Fire Extinguisher.

