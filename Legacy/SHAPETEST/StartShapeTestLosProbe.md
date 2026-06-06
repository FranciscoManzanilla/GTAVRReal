# _START_SHAPE_TEST_LOS_PROBE

--- ns: SHAPETEST aliases: ["0x7EE9F5D83DD4F90E"] --- ## START_SHAPE_TEST_LOS_PROBE  // 0x7EE9F5D83DD4F90E 0xEFAF4BA6 int START_SHAPE_TEST_LOS_PROBE(float x1, float y1, float z1, float x2, float y2, float z2, int traceFlags, Entity entity, int optionFlags);  Asynchronously starts a line-of-sight (raycast) world probe shape test.  enum eTraceFlags { None = 0, IntersectWorld = 1, IntersectVehicles = 2, IntersectPeds = 4, IntersectRagdolls = 8, IntersectObjects = 16, IntersectPickup = 32, IntersectGlass = 64, IntersectRiver = 128, IntersectFoliage = 256,  IntersectEverything = 511 }  enum eTraceOptionFlags { None = 0, OptionIgnoreGlass = 1, OptionIgnoreSeeThrough = 2, OptionIgnoreNoCollision = 4,  OptionDefault = 7 }  NOTE: Raycasts that intersect with mission_entites (flag = 2) has limited range and will not register for far away entites. The range seems to be about 30 metres.  Use the handle with [GET_SHAPE_TEST_RESULT](#_0x3D87450E15D98694) or [GET_SHAPE_TEST_RESULT_INCLUDING_MATERIAL](#_0x65287525D951F6BE) until it returns 0 or 2.  ## Parameters * **x1**: Starting X coordinate. * **y1**: Starting Y coordinate. * **z1**: Starting Z coordinate. * **x2**: Ending X coordinate. * **y2**: Ending Y coordinate. * **z2**: Ending Z coordinate. * **traceFlags**: Refer to `eTraceFlags`, this defines what the shape test will intersect with * **entity**: An entity to ignore, or 0. * **optionFlags**: Refer to `eTraceOptionFlags`, this defines additional options for the shape test  ## Return value A shape test handle.

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* int flags
* Entity entity
* int p8

### Return Value
* int

### Notes
* AP Hash: 0x0xEFAF4BA6
* Build: 323
* Asynchronously starts a line-of-sight (raycast) world probe shape test.

Use the handle with 0x3D87450E15D98694 or 0x65287525D951F6BE until it returns 0 or 2.

p8 is a bit mask with bits 1, 2 and/or 4, relating to collider types; 4 should usually be used.

