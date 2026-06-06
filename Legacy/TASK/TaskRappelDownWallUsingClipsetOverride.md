# _TASK_RAPPEL_DOWN_WALL_USING_CLIPSET_OVERRIDE

No description available.

### Parameters
* Ped ped
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* float minZ
* int ropeHandle
* const char* clipSet
* Any p10
* Any p11

### Return Value
* void

### Notes
* Build: 1868
* Attaches a ped to a rope and allows player control to rappel down a wall. Disables all collisions while on the rope.
p10: Usually 1 in the scripts, clipSet: Clipset to use for the task, minZ: Minimum Z that the player can descend to, ropeHandle: Rope to attach this task to created with ADD_ROPE

