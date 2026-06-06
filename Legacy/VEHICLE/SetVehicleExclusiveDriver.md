# _SET_VEHICLE_EXCLUSIVE_DRIVER

--- ns: VEHICLE aliases: ["0x41062318F23ED854"] --- ## SET_VEHICLE_EXCLUSIVE_DRIVER  // 0x41062318F23ED854 0xFF62D324 void SET_VEHICLE_EXCLUSIVE_DRIVER(Vehicle vehicle, cs_type(Ped) BOOL toggle);  Incorrectly named `SET_VEHICLE_EXCLUSIVE_DRIVER`; likely `SET_VEHICLE_ALLOW_*`.  Toggles a flag related to `SET_VEHICLE_EXCLUSIVE_DRIVER`, however, doesn't enable that feature (or trigger script events related to it).  See [`_SET_VEHICLE_EXCLUSIVE_DRIVER_2`](#_0xB5C51B5502E85E83).  NativeDB Removed Parameter 2: int index  ## Parameters * **vehicle**: * **toggle**:

### Parameters
* Vehicle vehicle
* Ped ped
* int index

### Return Value
* void

### Notes
* AP Hash: 0x0xAA8BD440
* Build: 323
* index: 0 - 1

Used to be incorrectly named _SET_VEHICLE_EXCLUSIVE_DRIVER_2

