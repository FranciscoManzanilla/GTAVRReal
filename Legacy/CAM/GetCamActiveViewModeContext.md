# _GET_CAM_ACTIVE_VIEW_MODE_CONTEXT

--- ns: CAM aliases: ["0x19CAFA3C87F7C2FF"] --- ## _GET_CAM_ACTIVE_VIEW_MODE_CONTEXT  // 0x19CAFA3C87F7C2FF int _GET_CAM_ACTIVE_VIEW_MODE_CONTEXT();  Enumerated type defined in camControlHelperMetadataViewModes:  enum eContext { ON_FOOT = 0, // [G|S]ET_FOLLOW_PED_CAM_* IN_VEHICLE = 1, // [G|S]ET_FOLLOW_VEHICLE_CAM_* ON_BIKE = 2, IN_BOAT = 3, IN_AIRCRAFT = 4, IN_SUBMARINE = 5, IN_HELI = 6, IN_TURRET = 7, }  ## Return value The active view mode context.

### Return Value
* int

### Notes
* Build: 323
* enum Context
{
	ON_FOOT,
	IN_VEHICLE,
	ON_BIKE,
	IN_BOAT,
	IN_AIRCRAFT,
	IN_SUBMARINE,
	IN_HELI,
	IN_TURRET
};

