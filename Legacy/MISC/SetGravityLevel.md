# _SET_GRAVITY_LEVEL

--- ns: MISC --- ## SET_GRAVITY_LEVEL  // 0x740E14FAD5842351 0x2D833F4A void SET_GRAVITY_LEVEL(int level);  enum eGravityLevel { GRAV_EARTH = 0, // earth gravity 9.8m/s2 GRAV_MOON = 1, // moon gravity 2.4m/s2 GRAV_LOW = 2, // very low gravity GRAV_ZERO = 3 // zero gravity }  ## Parameters * **level**:

### Parameters
* int level

### Return Value
* void

### Notes
* AP Hash: 0x0x2D833F4A
* Build: 323
* level can be from 0 to 3
0: 9.8 - normal
1: 2.4 - low
2: 0.1 - very low
3: 0.0 - off

