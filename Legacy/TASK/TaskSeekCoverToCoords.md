# _TASK_SEEK_COVER_TO_COORDS

--- ns: TASK --- ## TASK_SEEK_COVER_TO_COORDS  // 0x39246A6958EF072C 0xFFFE754E void TASK_SEEK_COVER_TO_COORDS(Ped ped, float x1, float y1, float z1, float x2, float y2, float z2, Any p7, BOOL p8);  from michael2: TASK::TASK_SEEK_COVER_TO_COORDS(ped, 967.5164794921875, -2121.603515625, 30.479299545288086, 978.94677734375, -2125.84130859375, 29.4752, -1, 1); appears to be shorter variation from michael3: TASK::TASK_SEEK_COVER_TO_COORDS(ped, -2231.011474609375, 263.6326599121094, 173.60195922851562, -1, 0);  ## Parameters * **ped**: * **x1**: * **y1**: * **z1**: * **x2**: * **y2**: * **z2**: * **p7**: * **p8**:

### Parameters
* Ped ped
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* int timeout
* BOOL shortRoute

### Return Value
* void

### Notes
* AP Hash: 0x0xFFFE754E
* Build: 323
* p8 causes the ped to take the shortest route to the cover position. It may have something to do with navmesh or pathfinding mechanics.

from michael2:
TASK::TASK_SEEK_COVER_TO_COORDS(ped, 967.5164794921875, -2121.603515625, 30.479299545288086, 978.94677734375, -2125.84130859375, 29.4752, -1, 1);


appears to be shorter variation
from michael3:
TASK::TASK_SEEK_COVER_TO_COORDS(ped, -2231.011474609375, 263.6326599121094, 173.60195922851562, -1, 0);

