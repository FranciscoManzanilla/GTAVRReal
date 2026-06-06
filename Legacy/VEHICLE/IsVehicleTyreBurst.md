# _IS_VEHICLE_TYRE_BURST

--- ns: VEHICLE --- ## IS_VEHICLE_TYRE_BURST  // 0xBA291848A0815CA9 0x48C80210 BOOL IS_VEHICLE_TYRE_BURST(Vehicle vehicle, int wheelID, BOOL isBurstToRim);  enum eVehicleWheels { WHEEL_LF = 0, // Vehicle Left front WHEEL_RF = 1, // Vehicle Right front WHEEL_LM = 2, // Vehicle Left middle WHEEL_RM = 3, // Vehicle Right middle WHEEL_LR = 4, // Vehicle Left rear WHEEL_RR = 5, // Vehicle Right rear WHEEL_BF = 6, // Bike front WHEEL_BR = 7, // Bike rear MAX_WHEELS = 8 };  ## Parameters * **vehicle**: The vehicle to check the tire status of * **wheelID**: The wheel id to check, see `eVehicleWheels` * **isBurstToRim**: Whether it should only return `true` if the tire is bursted to its rims  ## Return value Returns `true` if the vehicle tire is poped, `false` otherwise.

### Parameters
* Vehicle vehicle
* int wheelID
* BOOL completely

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x48C80210
* Build: 323
* wheelID used for 4 wheelers seem to be (0, 1, 4, 5)
completely - is to check if tire completely gone from rim.

'0 = wheel_lf / bike, plane or jet front
'1 = wheel_rf
'2 = wheel_lm / in 6 wheels trailer, plane or jet is first one on left
'3 = wheel_rm / in 6 wheels trailer, plane or jet is first one on right
'4 = wheel_lr / bike rear / in 6 wheels trailer, plane or jet is last one on left
'5 = wheel_rr / in 6 wheels trailer, plane or jet is last one on right
'45 = 6 wheels trailer mid wheel left
'47 = 6 wheels trailer mid wheel right

