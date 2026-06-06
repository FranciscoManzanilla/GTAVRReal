# _STAT_SET_DATE

--- ns: STATS --- ## STAT_SET_DATE  // 0x2C29BFB64F4FCBE4 0x36BE807B BOOL STAT_SET_DATE(Hash statName, Any* value, int numFields, BOOL save);  'value' is a structure to a structure, 'numFields' is how many fields there are in said structure (usually 7). The structure looks like this: int year int month int day int hour int minute int second int millisecond The decompiled scripts use TIME::GET_POSIX_TIME to fill this structure.  ## Parameters * **statName**: * **value**: * **numFields**: * **save**:  ## Return value

### Parameters
* Hash statName
* Any* value
* int numFields
* BOOL save

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x36BE807B
* Build: 323
* 'value' is a structure to a structure, 'numFields' is how many fields there are in said structure (usually 7).

The structure looks like this:

int year
int month
int day
int hour
int minute
int second
int millisecond

The decompiled scripts use TIME::GET_POSIX_TIME to fill this structure.

