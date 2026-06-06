# _IS_ENTRY_POINT_FOR_SEAT_CLEAR

--- ns: VEHICLE aliases: ["0x639431E895B9AA57", "_IS_VEHICLE_SEAT_ACCESSIBLE"] --- ## IS_ENTRY_POINT_FOR_SEAT_CLEAR  // 0x639431E895B9AA57 0xAB0E79EB BOOL IS_ENTRY_POINT_FOR_SEAT_CLEAR(Ped ped, Vehicle vehicle, cs_type(BOOL) int seatIndex, BOOL checkSide, BOOL leftSide);  Check if a entry point for a certain seat is clear, useful for checking if a vehicle seat is accesible. If you park your vehicle near a wall and the ped cannot enter/exit this side, the return value toggles from true (not blocked) to false (blocked).  Keep in mind, with checkSide set to true, that only certain vehicles have entry points on both sides for the same seat, like motorcycles, most normal vehicles don't have this and if the native doesn't find a entry point with the given parameters it will always return false. So for most normal usecases leaving checkSide set to false would result in the expected behavior.  ## Parameters * **ped**: The ped to check. * **vehicle**: The vehicle to check. * **seatIndex**: See eSeatPosition declared in [`IS_VEHICLE_SEAT_FREE`](#_0x22AC59A870E6A669). * **checkSide**: True to check the side of the entry point relative to the vehicle * **leftSide**: When checkSide is true together with this it only checks if entrypoints on the left side of the vehicle are clear, and for the right side when given false  ## Return value True if the entry point is accesible and the area is clear for the given ped.

### Parameters
* Ped ped
* Vehicle vehicle
* int seatIndex
* BOOL side
* BOOL onEnter

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xAB0E79EB
* Build: 323
* Check if a vehicle seat is accessible. If you park your vehicle near a wall and the ped cannot enter/exit this side, the return value toggles from true (not blocked) to false (blocked).

seatIndex  = -1 being the driver seat.
Use GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(vehicle) - 1 for last seat index.
side = only relevant for bikes/motorcycles to check if the left (false)/right (true) side is blocked.
onEnter = check if you can enter (true) or exit (false) a vehicle.

