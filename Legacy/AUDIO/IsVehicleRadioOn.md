# _IS_VEHICLE_RADIO_ON

--- ns: AUDIO aliases: ["0x0BE4BE946463F917", "_IS_VEHICLE_RADIO_ENABLED"] --- ## IS_VEHICLE_RADIO_ON  // 0x0BE4BE946463F917 BOOL IS_VEHICLE_RADIO_ON(Vehicle vehicle);  ## Parameters * **vehicle**: The vehicle to check  ## Return value Returns true if the given vehicle's radio on  ## Examples local radioEnabled = IsVehicleRadioEnabled(GetVehiclePedIsIn(PlayerPedId(), false)) print(radioEnabled) bool radioEnabled = API.IsVehicleRadioEnabled(API.GetVehiclePedIsIn(Game.PlayerPed.Handle, false)); Debug.WriteLine(radioEnabled.ToString());

### Parameters
* Vehicle vehicle

### Return Value
* BOOL

### Notes
* Build: 505

