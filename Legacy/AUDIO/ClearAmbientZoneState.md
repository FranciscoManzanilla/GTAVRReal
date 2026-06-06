# _CLEAR_AMBIENT_ZONE_STATE

--- ns: AUDIO --- ## CLEAR_AMBIENT_ZONE_STATE  // 0x218DD44AAAC964FF 0xCDFF3C82 void CLEAR_AMBIENT_ZONE_STATE(char* zoneName, BOOL forceUpdate);  Resets the ambient zone enabled/disabled status to its value before it was modified by this script  Default behaviour is that any state change only gets applied once the player leaves the zone.  ## Parameters * **zoneName**: the zone name to clear * **forceUpdate**: Whether ot not to force a zone to become disabled even if its currently active

### Parameters
* const char* zoneName
* BOOL p1

### Return Value
* void

### Notes
* AP Hash: 0x0xCDFF3C82
* Build: 323
* This function also has a p2, unknown. Signature AUDIO::CLEAR_AMBIENT_ZONE_STATE(const char* zoneName, bool p1, Any p2);

Still needs more research.

Full list of ambient zones by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/ambientZones.json

