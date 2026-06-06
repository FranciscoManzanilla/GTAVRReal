# _GET_VEHICLE_INDIVIDUAL_DOOR_LOCK_STATUS

--- ns: VEHICLE aliases: ["0xCA4AC3EAAE46EC7B", "_GET_VEHICLE_DOOR_DESTROY_TYPE"] --- ## GET_VEHICLE_INDIVIDUAL_DOOR_LOCK_STATUS  // 0xCA4AC3EAAE46EC7B int GET_VEHICLE_INDIVIDUAL_DOOR_LOCK_STATUS(Vehicle vehicle, int doorIndex);  See eDoorId declared in [`SET_VEHICLE_DOOR_SHUT`](#_0x93D9BD300D7789E5)  ## Parameters * **vehicle**: * **doorIndex**:  ## Return value Returns vehicle door lock state previously set with [`SET_VEHICLE_INDIVIDUAL_DOORS_LOCKED`](#_0xBE70724027F85BCD)

### Parameters
* Vehicle vehicle
* int doorId

### Return Value
* int

### Notes
* Build: 1103
* Returns vehicle door lock state previously set with SET_VEHICLE_INDIVIDUAL_DOORS_LOCKED

