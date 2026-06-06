# _GET_NUM_NAVMESHES_EXISTING_IN_AREA

--- ns: PATHFIND aliases: ["0x01708E8DD3FF8C65"] --- ## GET_NUM_NAVMESHES_EXISTING_IN_AREA  // 0x01708E8DD3FF8C65 0x76AFFBB5 int GET_NUM_NAVMESHES_EXISTING_IN_AREA(float posMinX, float posMinY, float posMinZ, float posMaxX, float posMaxY, float posMaxZ);  ## Parameters * **posMinX**: Min X Coordinate. * **posMinY**: Min Y Coordinate. * **posMinZ**: Min Z Coordinate. * **posMaxX**: Max X Coordinate. * **posMaxY**: Max Y Coordinate. * **posMaxZ**: Max Z Coordinate.  ## Return value Returns the number of navmeshes which exist in the given area (irrespective of whether they are currently loaded or not)

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2

### Return Value
* int

### Notes
* AP Hash: 0x0x76AFFBB5
* Build: 323

