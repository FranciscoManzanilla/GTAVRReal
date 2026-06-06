# _ADD_PATROL_ROUTE_NODE

--- ns: TASK --- ## ADD_PATROL_ROUTE_NODE  // 0x8EDF950167586B7C 0x21B48F10 void ADD_PATROL_ROUTE_NODE(int id, char* guardScenario, float x1, float y1, float z1, float x2, float y2, float z2, int waitTime);  x2,y2 and z2 are the coordinates to which the ped should look at  ## Parameters * **id**: is an integer that "identifies" the route node for linking to the route with ADD_PATROL_ROUTE_LINK. * **guardScenario**: can be "WORLD_HUMAN_GUARD_STAND" or "StandGuard" * **x1**: destination * **y1**: destination * **z1**: destination * **x2**: coordinates to which the ped should look * **y2**: coordinates to which the ped should look * **z2**: coordinates to which the ped should look * **waitTime**: written in ms  ## Examples  -- the guard will go toward vector3(1.0, 1.0, 1.0) coordinates looking toward vector3(0.0, 0.0, 0.0) coordinates waiting 1000ms with the WORLD_HUMAN_GUARD_STAND animation AddPatrolRouteNode(1, "WORLD_HUMAN_GUARD_STAND", vector3(1.0, 1.0, 1.0), vector3(0.0, 0.0, 0.0), 1000)

### Parameters
* int nodeId
* const char* nodeType
* float posX
* float posY
* float posZ
* float headingX
* float headingY
* float headingZ
* int duration

### Return Value
* void

### Notes
* AP Hash: 0x0x21B48F10
* Build: 323
* Example: 
TASK::ADD_PATROL_ROUTE_NODE(2, "WORLD_HUMAN_GUARD_STAND", -193.4915, -2378.864990234375, 10.9719, -193.4915, -2378.864990234375, 10.9719, 3000);

p0 is between 0 and 4 in the scripts.

p1 is "WORLD_HUMAN_GUARD_STAND" or "StandGuard".

p2, p3 and p4 is only one parameter sometimes in the scripts. Most likely a Vector3 hence p2, p3 and p4 are coordinates. 
Examples: 
TASK::ADD_PATROL_ROUTE_NODE(1, "WORLD_HUMAN_GUARD_STAND", l_739[7/*3*/], 0.0, 0.0, 0.0, 0);

TASK::ADD_PATROL_ROUTE_NODE(1, "WORLD_HUMAN_GUARD_STAND", l_B0[17/*44*/]._f3, l_B0[17/*44*/]._f3, 2000);

p5, p6 and p7 are for example set to: 1599.0406494140625, 2713.392578125, 44.4309.

p8 is an int, often random set to for example: MISC::GET_RANDOM_INT_IN_RANGE(5000, 10000).

