# _SET_TYRE_HEALTH

--- ns: VEHICLE --- ## _SET_TYRE_HEALTH  // 0x74C68EF97645E79D void _SET_TYRE_HEALTH(Vehicle vehicle, int wheelIndex, float health);  NativeDB Introduced: v1868  ## Parameters * **vehicle**: * **wheelIndex**: * **health**:

### Parameters
* Vehicle vehicle
* int wheelIndex
* float health

### Return Value
* void

### Notes
* Build: 1868
* SET_TYRE_WEAR_RATE must be active, otherwise values set to <1000.0f will default to 350.0f

Usable wheels:
0: wheel_lf
1: wheel_rf
2: wheel_lm1
3: wheel_rm1
4: wheel_lr
5: wheel_rr

