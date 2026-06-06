# __SET_DISABLE_EXPLODE_FROM_BODY_DAMAGE_RECEIVED_BY_AI_VEHICLE

--- ns: VEHICLE --- ## _SET_DISABLE_EXPLODE_FROM_BODY_DAMAGE_RECEIVED_BY_AI_VEHICLE  // 0xB0B7DF5CB876FF5E void _SET_DISABLE_EXPLODE_FROM_BODY_DAMAGE_RECEIVED_BY_AI_VEHICLE(Vehicle plane, BOOL disable);  NativeDB Introduced: v3407  Prevents the plane from exploding when taking body damage if the inflictor is an AI-controlled vehicle. Only works for planes.  ## Parameters * **plane**: * **disable**:

### Parameters
* Vehicle vehicle
* BOOL disable

### Return Value
* void

### Notes
* Build: 3407
* Prevents the vehicle from exploding when taking body damage if the inflictor is an AI-controlled vehicle. Only works for planes.

