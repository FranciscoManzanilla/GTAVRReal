# _SET_ALL_VEHICLE_GENERATORS_ACTIVE_IN_AREA

--- ns: VEHICLE --- ## SET_ALL_VEHICLE_GENERATORS_ACTIVE_IN_AREA  // 0xC12321827687FE4D 0xB4E0E69A void SET_ALL_VEHICLE_GENERATORS_ACTIVE_IN_AREA(float x1, float y1, float z1, float x2, float y2, float z2, BOOL p6, BOOL p7);   ## Parameters * **x1**: * **y1**: * **z1**: * **x2**: * **y2**: * **z2**: * **p6**: * **p7**:

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* BOOL toggle
* BOOL p7

### Return Value
* void

### Notes
* AP Hash: 0x0xB4E0E69A
* Build: 323
* When p6 is true, vehicle generators are active.
p7 seems to always be true in story mode scripts, but it's sometimes false in online scripts.

