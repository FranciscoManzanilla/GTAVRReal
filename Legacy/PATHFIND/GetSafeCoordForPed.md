# _GET_SAFE_COORD_FOR_PED

--- ns: PATHFIND --- ## GET_SAFE_COORD_FOR_PED  // 0xB61C8E878A4199CA 0xB370270A BOOL GET_SAFE_COORD_FOR_PED(float x, float y, float z, BOOL onlyOnPavement, Vector3* outPosition, int flags);  enum eSafePositionFlags { // Only navmesh polygons marked as pavement GSC_FLAG_ONLY_PAVEMENT = 1, // Only navmesh polygons not marked as "isolated" GSC_FLAG_NOT_ISOLATED = 2, // No navmesh polygons created from interiors GSC_FLAG_NOT_INTERIOR = 4, // No navmesh polygons marked as water GSC_FLAG_NOT_WATER = 8, // Only navmesh polygons marked as "network spawn candidate" GSC_FLAG_ONLY_NETWORK_SPAWN = 16, // Specify whether to use a flood-fill from the starting position, as opposed to scanning all polygons within the search volume GSC_FLAG_USE_FLOOD_FILL = 32 }  ## Parameters * **x**: The X coordinate of the point to check. * **y**: The Y coordinate of the point to check. * **z**: The Z coordinate of the point to check. * **onlyOnPavement**: Sets the `GSC_FLAG_ONLY_PAVEMENT` flag. * **outPosition**: The location of the safe coord. * **flags**: The search flags.  ## Return value Returns true if a safe coord was found and false otherwise.

### Parameters
* float x
* float y
* float z
* BOOL onGround
* Vector3* outPosition
* int flags

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xB370270A
* Build: 323
* Flags are:
1 = 1 = B02_IsFootpath
2 = 4 = !B15_InteractionUnk
4 = 0x20 = !B14_IsInterior
8 = 0x40 = !B07_IsWater
16 = 0x200 = B17_IsFlatGround
When onGround == true outPosition is a position located on the nearest pavement.

When a safe coord could not be found the result of a function is false and outPosition == Vector3.Zero.

In the scripts these flags are used: 0, 14, 12, 16, 20, 21, 28. 0 is most commonly used, then 16. 

16 works for me, 0 crashed the script.

