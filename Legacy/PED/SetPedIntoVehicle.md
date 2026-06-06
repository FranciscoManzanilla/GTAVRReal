# _SET_PED_INTO_VEHICLE

--- ns: PED --- ## SET_PED_INTO_VEHICLE  // 0xF75B0D629E1C063D 0x07500C79 void SET_PED_INTO_VEHICLE(Ped ped, Vehicle vehicle, int seatIndex);  ## Parameters * **ped**: * **vehicle**: * **seatIndex**: See eSeatPosition declared in [`IS_VEHICLE_SEAT_FREE`](#_0x22AC59A870E6A669). -2 for the first available seat.

### Parameters
* Ped ped
* Vehicle vehicle
* int seatIndex

### Return Value
* void

### Notes
* AP Hash: 0x0x07500C79
* Build: 323
* Ped: The ped to warp.
vehicle: The vehicle to warp the ped into.
Seat_Index: [-1 is driver seat, -2 first free passenger seat]

Moreinfo of Seat Index
DriverSeat = -1
Passenger = 0
Left Rear = 1
RightRear = 2

