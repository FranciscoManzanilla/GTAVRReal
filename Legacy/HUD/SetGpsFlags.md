# _SET_GPS_FLAGS

--- ns: HUD --- ## SET_GPS_FLAGS  // 0x5B440763A4C8D15B 0x60539BAB void SET_GPS_FLAGS(int p0, float p1);  Only the script that originally called SET_GPS_FLAGS can set them again. Another script cannot set the flags, until the first script that called it has called CLEAR_GPS_FLAGS. Doesn't seem like the flags are actually read by the game at all.  ## Parameters * **p0**: * **p1**:

### Parameters
* int p0
* float p1

### Return Value
* void

### Notes
* AP Hash: 0x0x60539BAB
* Build: 323
* Only the script that originally called SET_GPS_FLAGS can set them again. Another script cannot set the flags, until the first script that called it has called CLEAR_GPS_FLAGS.

Doesn't seem like the flags are actually read by the game at all.

