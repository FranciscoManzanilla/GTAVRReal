# _TASK_ENTER_VEHICLE

--- ns: TASK --- ## TASK_ENTER_VEHICLE  // 0xC20E50AA46D09CA8 0xB8689B4E void TASK_ENTER_VEHICLE(Ped ped, Vehicle vehicle, int timeout, int seatIndex, float speed, int flag, Any p6);  speed 1.0 = walk, 2.0 = run p5 1 = normal, 3 = teleport to vehicle, 8 = normal/carjack ped from seat, 16 = teleport directly into vehicle p6 is always 0  ## Parameters * **ped**: * **vehicle**: * **timeout**: * **seatIndex**: See eSeatPosition declared in [`IS_VEHICLE_SEAT_FREE`](#_0x22AC59A870E6A669). * **speed**: * **flag**: * **p6**:

### Parameters
* Ped ped
* Vehicle vehicle
* int timeout
* int seat
* float speed
* int flag
* const char* overrideEntryClipsetName

### Return Value
* void

### Notes
* AP Hash: 0x0xB8689B4E
* Build: 323
* speed 1.0 = walk, 2.0 = run
p5 1 = normal, 3 = teleport to vehicle, 16 = teleport directly into vehicle
p6 is always 0

Usage of seat 
-1 = driver
0 = passenger
1 = left back seat
2 = right back seat
3 = outside left
4 = outside right

