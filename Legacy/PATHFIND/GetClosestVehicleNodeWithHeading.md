# _GET_CLOSEST_VEHICLE_NODE_WITH_HEADING

--- ns: PATHFIND --- ## GET_CLOSEST_VEHICLE_NODE_WITH_HEADING  // 0xFF071FB798B803B0 0x8BD5759B BOOL GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(float x, float y, float z, Vector3* outPosition, float* outHeading, int nodeFlags, float zMeasureMult, int zTolerance);  Same as [`GET_CLOSEST_VEHICLE_NODE`](#_0x240A18690AE96513), but with the node flag `GCNF_GET_HEADING` set, causing the native to also return the heading.  ## Parameters * **x**: X coordinate * **y**: Y coordinate * **z**: Z coordinate * **outPosition**: Pointer to the found nodes coords * **outHeading**: Pointer to the found nodes heading * **nodeFlags**: Node flags, see [`GET_CLOSEST_VEHICLE_NODE`](#_0x240A18690AE96513) * **zMeasureMult**: How strongly the difference in the Z direction should be weighted * **zTolerance**: How far apart the Z coords have to be before `zMeasureMult` kicks in  ## Return value Returns the closest vehicle node with its heading.

### Parameters
* float x
* float y
* float z
* Vector3* outPosition
* float* outHeading
* int nodeType
* float p6
* float p7

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x8BD5759B
* Build: 323
* p5, p6 and p7 seems to be about the same as p4, p5 and p6 for GET_CLOSEST_VEHICLE_NODE. p6 and/or p7 has something to do with finding a node on the same path/road and same direction(at least for this native, something to do with the heading maybe). Edit this when you find out more.

nodeType: 0 = main roads, 1 = any dry path, 3 = water
p6 is always 3.0
p7 is always 0

gtaforums.com/topic/843561-pathfind-node-types

Example of usage, moving vehicle to closest path/road:
Vector3 coords = ENTITY::GET_ENTITY_COORDS(playerVeh, true);
Vector3 closestVehicleNodeCoords; 
float roadHeading; 
PATHFIND::GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(coords.x, coords.y, coords.z, &closestVehicleNodeCoords, &roadHeading, 1, 3, 0); 
ENTITY::SET_ENTITY_HEADING(playerVeh, roadHeading);
ENTITY::SET_ENTITY_COORDS(playerVeh, closestVehicleNodeCoords.x, closestVehicleNodeCoords.y, closestVehicleNodeCoords.z, 1, 0, 0, 1);
VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(playerVeh);

------------------------------------------------------------------
C# Example (ins1de) : https://pastebin.com/fxtMWAHD

