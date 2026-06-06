# _LOCK_RADIO_STATION

--- ns: AUDIO aliases: ["0x94f2e83ead7e6b82","_SET_RADIO_STATION_DISABLED", "_LOCK_RADIO_STATION"] --- ## LOCK_RADIO_STATION  // 0x477D9DB48F889591 void LOCK_RADIO_STATION(char* radioStationName, BOOL toggle);  This disables the radio station completely - it won't be selectable on the radio wheel or ever be heard coming from a vehicle/ambient emitter  NativeDB Introduced: v1493  ## Parameters * **radioStationName**: * **toggle**:

### Parameters
* const char* radioStationName
* BOOL toggle

### Return Value
* void

### Notes
* Build: 1493
* Disables the radio station (hides it from the radio wheel).

