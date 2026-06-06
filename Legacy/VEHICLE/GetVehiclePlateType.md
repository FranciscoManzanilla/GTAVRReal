# _GET_VEHICLE_PLATE_TYPE

--- ns: VEHICLE --- ## GET_VEHICLE_PLATE_TYPE  // 0x9CCC9525BF2408E0 0x65CA9286 int GET_VEHICLE_PLATE_TYPE(Vehicle vehicle);  Returns the plates a vehicle has.  enum eVehiclePlateType { VPT_FRONT_AND_BACK_PLATES = 0, VPT_FRONT_PLATES = 1, VPT_BACK_PLATES = 2, VPT_NONE = 3, };  Motorcycles with no visible plates will sometimes return a 2 for unknown reasons.  ## Parameters * **vehicle**:  ## Return value Returns the vehicle plate type, refer to `eVehiclePlateType`

### Parameters
* Vehicle vehicle

### Return Value
* int

### Notes
* AP Hash: 0x0x65CA9286
* Build: 323

