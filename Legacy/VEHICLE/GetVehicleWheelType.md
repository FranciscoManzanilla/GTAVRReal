# _GET_VEHICLE_WHEEL_TYPE

--- ns: VEHICLE --- ## GET_VEHICLE_WHEEL_TYPE  // 0xB3ED1BFB4BE636DC 0xDA58D7AE int GET_VEHICLE_WHEEL_TYPE(Vehicle vehicle);  enum eVehicleWheelType { VWT_SPORT = 0, VWT_MUSCLE = 1, VWT_LOWRIDER = 2, VWT_SUV = 3, VWT_OFFROAD = 4, VWT_TUNER = 5, VWT_BIKE = 6, VWT_HIEND = 7, // Benny's Original VWT_SUPERMOD1 = 8, // Benny's Bespoke VWT_SUPERMOD2 = 9, // Open Wheel VWT_SUPERMOD3 = 10, // Street VWT_SUPERMOD4 = 11, // Track VWT_SUPERMOD5 = 12, };  ## Parameters * **vehicle**:  ## Return value Returns an eVehicleWheelType integer value.

### Parameters
* Vehicle vehicle

### Return Value
* int

### Notes
* AP Hash: 0x0xDA58D7AE
* Build: 323
* Returns an int

Wheel Types:
0: Sport
1: Muscle
2: Lowrider
3: SUV
4: Offroad
5: Tuner
6: Bike Wheels
7: High End
8: Benny's Originals
9: Benny's Bespoke
10: Racing
11: Street
12: Track

Tested in Los Santos Customs

