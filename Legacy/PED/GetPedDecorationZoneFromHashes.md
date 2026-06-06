# _GET_PED_DECORATION_ZONE_FROM_HASHES

--- ns: PED aliases: ["_GET_TATTOO_ZONE"] --- ## GET_PED_DECORATION_ZONE_FROM_HASHES  // 0x9FD452BFBE7A7A8B 0x3543019E int GET_PED_DECORATION_ZONE_FROM_HASHES(Hash collection, Hash overlay);  enum ePedDecorationZone { ZONE_TORSO = 0, ZONE_HEAD = 1, ZONE_LEFT_ARM = 2, ZONE_RIGHT_ARM = 3, ZONE_LEFT_LEG = 4, ZONE_RIGHT_LEG = 5, ZONE_UNKNOWN = 6, ZONE_NONE = 7 };  ## Parameters * **collection**: * **overlay**:  ## Return value Returns the doeciration zone for the specific collection and overlay combination, refer to `ePedDecorationZone`

### Parameters
* Hash collection
* Hash overlay

### Return Value
* int

### Notes
* AP Hash: 0x0x3543019E
* Build: 323
* Returns the zoneID for the overlay if it is a member of collection.
enum ePedDecorationZone
{
	ZONE_TORSO = 0,
	ZONE_HEAD = 1,
	ZONE_LEFT_ARM = 2,
	ZONE_RIGHT_ARM = 3,
	ZONE_LEFT_LEG = 4,
	ZONE_RIGHT_LEG = 5,
	ZONE_MEDALS = 6,
	ZONE_INVALID = 7
};

Full list of ped overlays / decorations by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/pedOverlayCollections.json

