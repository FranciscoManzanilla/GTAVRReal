# _SET_WIND_DIRECTION

--- ns: MISC --- ## SET_WIND_DIRECTION  // 0xEB0F4468467B4528 0x381AEEE9 void SET_WIND_DIRECTION(float direction);  Sets the wind direction. The wind direction will stay persistent until it is reset (see examples).  ## Parameters * **direction**: the [wind direction](https://en.wikipedia.org/wiki/Wind_direction) in radians  ## Examples -- 180 degrees, wind will blow from the south SetWindDirection(math.rad(180.0))  -- Allows the game to dynamically change the wind direction again SetWindDirection(-1)  // 180 degrees, wind will blow from the south SetWindDirection(180.0 * (Math.PI / 180));  // Allows the game to dynamically change the wind direction again SetWindDirection(-1);  // 180 degrees, wind will blow from the south SetWindDirection(3.1415f);  // Allows the game to dynamically change the wind direction again SetWindDirection(-1f);

### Parameters
* float direction

### Return Value
* void

### Notes
* AP Hash: 0x0x381AEEE9
* Build: 323
* The wind direction in radians
180 degrees (PI), wind will blow from the south. Setting this value to a negative number resumes the random wind direction changes provided by the game.

