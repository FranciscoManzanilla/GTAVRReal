# _GET_PED_IN_VEHICLE_SEAT

--- ns: VEHICLE --- ## GET_PED_IN_VEHICLE_SEAT  // 0xBB40DD2270B65366 0x388FDE9A Ped GET_PED_IN_VEHICLE_SEAT(Vehicle vehicle, int seatIndex);  Gets the ped in the specified seat of the passed vehicle.  If there is no ped in the seat, and the game considers the vehicle as ambient population, this will create a random occupant ped in the seat, which may be cleaned up by the game fairly soon if not marked as script-owned mission entity.  **NativeDB Added Parameter 3**: BOOL p2 (uses a different GetOccupant function)  ## Parameters * **vehicle**: The vehicle to get the ped for. * **seatIndex**: See eSeatPosition declared in [`IS_VEHICLE_SEAT_FREE`](#_0x22AC59A870E6A669).  ## Return value A handle to a ped in the specified vehicle seat, or 0 if no such ped existed.  ## Examples -- Checks if the player ped is in the drivers seat of the vehicle they are in. if GetPedInVehicleSeat(GetVehiclePedIsIn(PlayerPedId()), -1) == PlayerPedId() then print("The player is the driver of this vehicle.") else print("The player is not the driver of this vehicle.") end

### Parameters
* Vehicle vehicle
* int seatIndex
* BOOL p2

### Return Value
* Ped

### Notes
* AP Hash: 0x0x388FDE9A
* Build: 323
* If there is no ped in the seat, and the game considers the vehicle as ambient population, this will create a random occupant ped in the seat, which may be cleaned up by the game fairly soon if not marked as script-owned mission entity.

Seat indexes:
-1 = Driver
0 = Front Right Passenger
1 = Back Left Passenger
2 = Back Right Passenger
3 = Further Back Left Passenger (vehicles > 4 seats)
4 = Further Back Right Passenger (vehicles > 4 seats)
etc.

If p2 is true it uses a different GetOccupant function.

