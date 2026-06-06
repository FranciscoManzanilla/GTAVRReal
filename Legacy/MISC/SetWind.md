# _SET_WIND

--- ns: MISC --- ## SET_WIND  // 0xAC3A74E8384A9919 0xC6294698 void SET_WIND(float speed);  Sets the the raw wind speed value. The wind speed will stay persistent until it is reset (see examples).  ## Parameters * **speed**: The wind speed (clamped to between 0.0 and 1.0)  ## Examples -- Stops all and any wind SetWind(0)  -- Sets the wind to 6 m/s SetWind(0.5)  -- Allows the game dynamically change the wind again SetWind(-1)  // Stops all and any wind SetWind(0);  // Sets the wind to 6 m/s SetWind(0.5);  // Allows the game dynamically change the wind again SetWind(-1);  // Stops all and any wind SetWind(0f);  // Sets the wind to 6 m/s SetWind(0.5f);  // Allows the game dynamically change the wind again SetWind(-1f);

### Parameters
* float speed

### Return Value
* void

### Notes
* AP Hash: 0x0xC6294698
* Build: 323
* Sets the the normalized wind speed value. The wind speed clamps always at 12.0, SET_WIND sets the wind in a percentage, 0.0 is 0 and 1.0 is 12.0. Setting this value to a negative number resumes the random wind speed changes provided by the game.

