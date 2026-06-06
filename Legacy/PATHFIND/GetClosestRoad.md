# _GET_CLOSEST_ROAD

--- ns: PATHFIND --- ## GET_CLOSEST_ROAD  // 0x132F52BBA570FE92 0x567B0E11 cs_type(Any) bool GET_CLOSEST_ROAD(float x, float y, float z, float minimumEdgeLength, int minimumLaneCount, Vector3* srcNode, Vector3* targetNode, int* laneCountForward, int* laneCountBackward, float* width, BOOL onlyMajorRoads);  Finds an edge (node connection to another node) that satisfies the specified criteria.  ## Parameters * **x**: x position * **y**: y position * **z**: z position * **minimumEdgeLength**: Minimum distance the srcNode must be from the targetNode. * **minimumLaneCount**: Minimum number of lanes the connection must have. * **srcNode**: Position of the edge source * **targetNode**: Position of the edge target * **laneCountForward**: Lane count forward * **laneCountBackward**: Lane count backwards * **width**: Width of gap in middle of road between forward and backward lanes. * **onlyMajorRoads**: Return major roads only.  ## Return value Returns `true` if a road was found, `false` otherwise.

### Parameters
* float x
* float y
* float z
* float p3
* int p4
* Vector3* p5
* Vector3* p6
* Any* p7
* Any* p8
* float* p9
* BOOL p10

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x567B0E11
* Build: 323
* p1 seems to be always 1.0f in the scripts

