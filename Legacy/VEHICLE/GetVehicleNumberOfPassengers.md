# _GET_VEHICLE_NUMBER_OF_PASSENGERS

--- ns: VEHICLE --- ## GET_VEHICLE_NUMBER_OF_PASSENGERS  // 0x24CB2137731FFE89 0x1EF20849 int GET_VEHICLE_NUMBER_OF_PASSENGERS(Vehicle vehicle);  Gets the number of passengers, NOT including the driver. Use IS_VEHICLE_SEAT_FREE(Vehicle, -1) to also check for the driver  ## Parameters * **vehicle**:  ## Return value

### Parameters
* Vehicle vehicle
* BOOL includeDriver
* BOOL includeDeadOccupants

### Return Value
* int

### Notes
* AP Hash: 0x0x1EF20849
* Build: 323
* Gets the number of passengers.

This native was modified in b2545 to take two additional parameters, allowing you to include the driver or exclude dead passengers.

To keep it working like before b2545, set includeDriver to false and includeDeadOccupants to true.

