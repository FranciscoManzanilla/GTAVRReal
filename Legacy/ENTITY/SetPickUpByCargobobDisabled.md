# _SET_PICK_UP_BY_CARGOBOB_DISABLED

--- ns: ENTITY aliases: ["0xD7B80E7C3BEFC396"] --- ## SET_PICK_UP_BY_CARGOBOB_DISABLED  // 0xD7B80E7C3BEFC396 void SET_PICK_UP_BY_CARGOBOB_DISABLED(Entity entity, cs_type(Any) BOOL toggle);  Configures an entity to either allow or prevent it from being picked up by Cargobobs.  NativeDB Introduced: v1180  ## Parameters * **entity**: The entity to be configured for pick up by Cargobob. * **toggle**: A boolean value where `true` prevents the entity from being picked up by Cargobobs, and `false` allows it.  ## Examples -- This example prevents a entity (in this example the vehicle of the player) from being picked up by any Cargobobs.  -- Retrieve the player ped local playerPed = PlayerPedId()  -- Retrieve the player's vehicle (cargobob) local vehicle = GetVehiclePedIsIn(playerPed, false)  -- Check if the vehicle exists in the game world. if not DoesEntityExist(vehicle) then -- If the vehicle does not exist, end the execution of the code here. return end  -- Prevent the vehicle from being picked up by Cargobobs. SetPickUpByCargobobDisabled(vehicle, true)  // This example prevents a entity (in this example the vehicle of the player) from being picked up by any Cargobobs.  // Retrieve the player ped. const playerPed = PlayerPedId();  // Retrieve the player's vehicle. const vehicle = GetVehiclePedIsIn(playerPed, false);  // Check if the vehicle exists in the game world. if (!DoesEntityExist(vehicle)) { // If the vehicle does not exist, end the execution of the code here. return; }  // Prevent the vehicle from being picked up by Cargobobs. SetPickUpByCargobobDisabled(vehicle, true);  // This example prevents a entity (in this example the vehicle of the player) from being picked up by any Cargobobs. using static CitizenFX.Core.Native.API;  // Retrieve the player ped. int playerPed = PlayerPedId();  // Retrieve the player's vehicle. int vehicle = GetVehiclePedIsIn(playerPed, false);  // Check if the vehicle exists in the game world. if (!DoesEntityExist(vehicle)) { // If the vehicle does not exist, end the execution of the code here. return; }  // Prevent the vehicle from being picked up by Cargobobs. SetPickUpByCargobobDisabled(vehicle, true);

### Parameters
* Entity entity
* BOOL toggle

### Return Value
* void

### Notes
* Build: 1180

