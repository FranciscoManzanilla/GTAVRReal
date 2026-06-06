# _TOGGLE_VEHICLE_MOD

--- ns: VEHICLE --- ## TOGGLE_VEHICLE_MOD  // 0x2A1F4F37F95BAD08 0xD095F811 void TOGGLE_VEHICLE_MOD(Vehicle vehicle, int modType, BOOL toggle);  Enables or disables a vehicle mod by index (`modType`) for a given vehicle.  `eVehicleModType` enum, used for `modType` index can be found under [`SET_VEHICLE_MOD`](#_0x6AF0636DDEDCB6DD).  ## Parameters * **vehicle**: The vehicle handle * **modType**: Refer to eVehicleModType in [`SET_VEHICLE_MOD`](#_0x6AF0636DDEDCB6DD). * **toggle**: A bool indicating whether the mod should be enabled/disabled (true/false)

### Parameters
* Vehicle vehicle
* int modType
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0xD095F811
* Build: 323
* Toggles:
UNK17 - 17
Turbo - 18
UNK19 - 19
Tire Smoke - 20
UNK21 - 21
Xenon Headlights - 22

