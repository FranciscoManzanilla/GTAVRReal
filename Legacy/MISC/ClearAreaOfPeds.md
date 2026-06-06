# _CLEAR_AREA_OF_PEDS

--- ns: MISC --- ## CLEAR_AREA_OF_PEDS  // 0xBE31FD6CE464AC59 0x25BE7FA8 void CLEAR_AREA_OF_PEDS(float x, float y, float z, float radius, cs_type(int) BOOL createNetEvent);  Clears an area of peds at the given coordinates and radius.  ## Examples -- Clear the area, do also create an event ClearAreaOfPeds(0.0, 0.0, 0.0, 10000.0, true)  ## Parameters * **x**: The x coordinate of where to clear peds. * **y**: The y coordinate of where to clear peds. * **z**: The z coordinate of where to clear peds. * **radius**: The area radius to clear peds. * **createNetEvent**: specifies whether a `CClearAreaEvent` event of should be created for online use.

### Parameters
* float x
* float y
* float z
* float radius
* int flags

### Return Value
* void

### Notes
* AP Hash: 0x0x25BE7FA8
* Build: 323
* Example:       CLEAR_AREA_OF_PEDS(0, 0, 0, 10000, 1);

