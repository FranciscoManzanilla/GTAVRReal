# _IS_VEHICLE_MOD_GEN9_EXCLUSIVE

--- ns: VEHICLE aliases: ["0x00834EAC4A96E010", "_IS_VEHICLE_MOD_HSW_EXCLUSIVE"] ---  ## IS_VEHICLE_MOD_GEN9_EXCLUSIVE  // 0x00834EAC4A96E010 0xEF66663B BOOL IS_VEHICLE_MOD_GEN9_EXCLUSIVE(Vehicle vehicle, int modType, int modIndex);   ## Parameters * **vehicle**: The vehicle handle * **modType**: The mod type (see [`SET_VEHICLE_MOD`](#_0x6AF0636DDEDCB6DD)) * **modIndex**: The mod index  ## Return value Returns whether the specified mod is exclusive to gen9 or not.

### Parameters
* Vehicle vehicle
* int modType
* int modIndex

### Return Value
* BOOL

### Notes
* Build: 2699
* Returns true for any mod part listed in GEN9_EXCLUSIVE_ASSETS_VEHICLES_FILE.

