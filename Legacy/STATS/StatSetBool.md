# _STAT_SET_BOOL

--- ns: STATS --- ## STAT_SET_BOOL  // 0x4B33C4243DE0C432 0x55D79DFB BOOL STAT_SET_BOOL(Hash statName, BOOL value, BOOL save);  Example: STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MPPLY_MELEECHLENGECOMPLETED"), trur, true);  ## Parameters * **statName**: * **value**: * **save**:  ## Return value

### Parameters
* Hash statName
* BOOL value
* BOOL save

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x55D79DFB
* Build: 323
* Example:
 STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MPPLY_MELEECHLENGECOMPLETED"), trur, true);

