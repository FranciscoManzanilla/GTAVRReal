# _STAT_GET_USER_ID

--- ns: STATS --- ## STAT_GET_USER_ID  // 0x2365C388E393BBE2 0xE2E8B6BA char* STAT_GET_USER_ID(Any p0);  Needs more research. Seems to return "STAT_UNKNOWN" if no such user id exists.  ## Parameters * **p0**:  ## Return value

### Parameters
* Hash statHash

### Return Value
* const char*

### Notes
* AP Hash: 0x0xE2E8B6BA
* Build: 323
* Returns the rockstar ID (user id) value of a given stat. Returns "STAT_UNKNOWN" if the statHash is invalid or the stat has no userId

