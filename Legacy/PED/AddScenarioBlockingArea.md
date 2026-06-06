# _ADD_SCENARIO_BLOCKING_AREA

--- ns: PED --- ## ADD_SCENARIO_BLOCKING_AREA  // 0x1B5C85C612E5256E 0xA38C0234 int ADD_SCENARIO_BLOCKING_AREA(float posMinX, float posMinY, float posMinZ, float posMaxX, float posMaxY, float posMaxZ, BOOL network, BOOL cancelActive, BOOL blockPeds, BOOL blockVehicles);  Sets an area where scenarios are blocked   ## Parameters * **posMinX**: Min X Coordinate. * **posMinY**: Min Y Coordinate. * **posMinZ**: Min Z Coordinate. * **posMaxX**: Max X Coordinate. * **posMaxY**: Max Y Coordinate. * **posMaxZ**: Max Z Coordinate. * **network**: Optionally networked to all other players * **cancelActive**: Should this cause peds already in active scenario points in the area specified to leave * **blockPeds**: if this area effects scenarios with peds * **blockVehicles**: if this area effects scenarios with vehicles  ## Return value

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* BOOL p6
* BOOL p7
* BOOL p8
* BOOL p9
* Any p10

### Return Value
* int

### Notes
* AP Hash: 0x0xA38C0234
* Build: 323

