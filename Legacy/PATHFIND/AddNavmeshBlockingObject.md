# _ADD_NAVMESH_BLOCKING_OBJECT

--- ns: PATHFIND --- ## ADD_NAVMESH_BLOCKING_OBJECT  // 0xFCD5C8E06E502F5A 0x2952BA56 Any ADD_NAVMESH_BLOCKING_OBJECT(float x, float y, float z, float width, float length, float height, float heading, BOOL bPermanent, int flags);  Creates a navmesh blocking object, vehicles will avoid driving through this area.  Only 32 blocking objects may exist at a given time and must be manually managed. See [`REMOVE_NAVMESH_BLOCKING_OBJECT`](#_0x46399A7895957C0E) and [`onResourceStop`](https://docs.fivem.net/docs/scripting-reference/events/list/onResourceStop/)  enum eBlockingObjectFlags { // Default Flag BLOCKING_OBJECT_DEFAULT = 0, // Blocking object will block wander paths BLOCKING_OBJECT_WANDERPATH = 1, // Blocking object will block (regular) shortest-paths BLOCKING_OBJECT_SHORTESTPATH = 2, // Blocking object will block flee paths BLOCKING_OBJECT_FLEEPATH = 4, // Blocking object will block all paths BLOCKING_OBJECT_ALLPATHS = 7, }  ## Parameters * **x**: The x coordinate to create the block on. * **y**: The y coordinate. * **z**: The z coordinate. * **width**: The width of the block. * **length**: The length of the block. * **height**: The height of the block. * **heading**: The heading of object in degrees. * **bPermanent**: A boolean indicating if the blocking object is permanent (`true`/`false`). * **flags**: Flag for the blocking object, refer to `eBlockingObjectFlags`.  ## Return value

### Parameters
* float p0
* float p1
* float p2
* float p3
* float p4
* float p5
* float p6
* BOOL p7
* Any p8

### Return Value
* int

### Notes
* AP Hash: 0x0x2952BA56
* Build: 323

