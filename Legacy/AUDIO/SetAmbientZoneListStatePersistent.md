# _SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT

--- ns: AUDIO --- ## SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT  // 0xF3638DAE8C4045E1 0x5F5A2605 void SET_AMBIENT_ZONE_LIST_STATE_PERSISTENT(char* ambientZone, BOOL enabled, BOOL forceUpdate);   ## Parameters * **ambientZone**: * **enabled**: Enables/disables a list of ambient zones persistently * **forceUpdate**: Set to true to force a zone to become disabled even if its currently active, default behaviour is to only change state when the player leaves the zone.

### Parameters
* const char* ambientZone
* BOOL p1
* BOOL p2

### Return Value
* void

### Notes
* AP Hash: 0x0x5F5A2605
* Build: 323
* Full list of ambient zones by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/ambientZones.json

