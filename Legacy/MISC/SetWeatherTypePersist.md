# _SET_WEATHER_TYPE_PERSIST

--- ns: MISC --- ## SET_WEATHER_TYPE_PERSIST  // 0x704983DF373B198F 0xC6C04C75 void SET_WEATHER_TYPE_PERSIST(char* weatherType);  Sets the current weather type to persist indefinitely until changed.  **Note:** This native is not supported in networked sessions. Please refer to [`SET_OVERRIDE_WEATHER`](#_0xA43D5C6FE51ADBEF) or [`SET_WEATHER_TYPE_NOW_PERSIST`](#_0xED712CA327900C8A) if you want to override weather in networked sessions.  NativeDB Introduced: v323  ## Parameters * **weatherType**: The weather type to be set as persistent. Refer to [`SET_WEATHER_TYPE_NOW`](#_0x29B487C359E19889) for a list of weather type strings.

### Parameters
* const char* weatherType

### Return Value
* void

### Notes
* AP Hash: 0x0xC6C04C75
* Build: 323
* The following weatherTypes are used in the scripts:
"CLEAR"
"EXTRASUNNY"
"CLOUDS"
"OVERCAST"
"RAIN"
"CLEARING"
"THUNDER"
"SMOG"
"FOGGY"
"XMAS"
"SNOW"
"SNOWLIGHT"
"BLIZZARD"
"HALLOWEEN"
"NEUTRAL"

