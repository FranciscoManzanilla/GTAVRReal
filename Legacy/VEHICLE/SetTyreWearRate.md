# _SET_TYRE_WEAR_RATE

No description available.

### Parameters
* Vehicle vehicle
* int wheelIndex
* float multiplier

### Return Value
* void

### Notes
* Build: 1868
* Needs to be run for tire wear to work. Multiplier affects the downforce and how fast the tires will wear out, higher values essentially make the vehicle slower on straights and its tires will wear down quicker when cornering. Value must be >0f.
Default value in Rockstar's Open Wheel Race JSON's ("owrtws", "owrtwm", "owrtwh") is 1.0

Usable wheels:
0: wheel_lf
1: wheel_rf
2: wheel_lm1
3: wheel_rm1
4: wheel_lr
5: wheel_rr

