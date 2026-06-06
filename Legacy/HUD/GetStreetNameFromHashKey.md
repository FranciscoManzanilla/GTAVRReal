# _GET_STREET_NAME_FROM_HASH_KEY

--- ns: HUD --- ## GET_STREET_NAME_FROM_HASH_KEY  // 0xD0EF8A959B8A4CB9 0x1E8E310C char* GET_STREET_NAME_FROM_HASH_KEY(Hash hash);  Converts the hash of a street name into a readable string. To retrieve a hash for a given (street) coordinate, see [`GET_STREET_NAME_AT_COORD`](#_0x2EB41072B4C1E4C0).  ## Parameters * **hash**:  ## Return value

### Parameters
* Hash hash

### Return Value
* const char*

### Notes
* AP Hash: 0x0x1E8E310C
* Build: 323
* This functions converts the hash of a street name into a readable string.

For how to get the hashes, see PATHFIND::GET_STREET_NAME_AT_COORD.

