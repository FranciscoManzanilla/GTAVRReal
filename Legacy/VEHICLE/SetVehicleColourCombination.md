# _SET_VEHICLE_COLOUR_COMBINATION

--- ns: VEHICLE --- ## SET_VEHICLE_COLOUR_COMBINATION  // 0x33E8CD3322E2FE31 0xA557AEAD void SET_VEHICLE_COLOUR_COMBINATION(Vehicle vehicle, int colorCombination);  Sets the selected vehicle's colors to their default value (specific variant specified using the colorCombination parameter).  Range of possible values for colorCombination is currently unknown, I couldn't find where these values are stored either (Disquse's guess was vehicles.meta but I haven't seen it in there.)  ## Parameters * **vehicle**: The vehicle to modify. * **colorCombination**: One of the default color values of the vehicle.  ## Examples local vehicle = GetVehiclePedIsIn(PlayerPedId(), false) local index = math.random(0, 16) SetVehicleColourCombination(vehicle, index)

### Parameters
* Vehicle vehicle
* int colorCombination

### Return Value
* void

### Notes
* AP Hash: 0x0xA557AEAD
* Build: 323
* Sets the selected vehicle's colors to the specified index of the color combination found in the vehicle's carvariations.meta entry.

