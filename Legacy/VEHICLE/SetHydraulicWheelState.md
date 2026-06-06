# _SET_HYDRAULIC_WHEEL_STATE

--- ns: VEHICLE aliases: ["0x8EA86DF356801C7D"] --- ## _SET_HYDRAULIC_WHEEL_STATE  // 0x8EA86DF356801C7D void _SET_HYDRAULIC_WHEEL_STATE(Vehicle vehicle, int state);  ## Parameters * **vehicle**: * **state**:

### Parameters
* Vehicle vehicle
* int wheelId
* int state
* float value
* Any p4

### Return Value
* void

### Notes
* Build: 505
* Sets vehicle wheel hydraulic states transition. Known states:
0 - reset
1 - raise wheel (uses value arg, works just like _SET_VEHICLE_HYDRAULIC_WHEEL_VALUE)
2 - jump using wheel

