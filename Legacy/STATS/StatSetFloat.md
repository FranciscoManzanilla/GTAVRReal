# _STAT_SET_FLOAT

--- ns: STATS --- ## STAT_SET_FLOAT  // 0x4851997F37FE9B3C 0x6CEA96F2 BOOL STAT_SET_FLOAT(Hash statName, float value, BOOL save);  Example: STATS::STAT_SET_FLOAT(MISC::GET_HASH_KEY("MP0_WEAPON_ACCURACY"), 66.6f, true);  ## Parameters * **statName**: * **value**: * **save**:  ## Return value

### Parameters
* Hash statName
* float value
* BOOL save

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x6CEA96F2
* Build: 323
* Example:
 STATS::STAT_SET_FLOAT(MISC::GET_HASH_KEY("MP0_WEAPON_ACCURACY"), 66.6f, true);

