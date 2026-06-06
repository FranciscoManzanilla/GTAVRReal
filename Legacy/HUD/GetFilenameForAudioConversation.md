# _GET_FILENAME_FOR_AUDIO_CONVERSATION

--- ns: HUD aliases: ["0x7B5280EBA9840C72", "_GET_LABEL_TEXT"] --- ## GET_FILENAME_FOR_AUDIO_CONVERSATION  // 0x7B5280EBA9840C72 0x95C4B5AD char* GET_FILENAME_FOR_AUDIO_CONVERSATION(char* labelName);  Gets a localized string literal from a label name. This is used to get the filename of the audio conversation associated with the provided label name.  ## Parameters * **labelName**: The label name for which the audio conversation filename is requested.  ## Return value Returns the filename associated with the provided labelName.  ## Examples  -- Get the vehicle in which the player is currently seated local vehicle = GetVehiclePedIsIn(PlayerPedId(), false)  -- Get the model of the vehicle local model = GetEntityModel(vehicle)  -- Get the display name of the vehicle model local displayName = GetDisplayNameFromVehicleModel(model)  -- Get the label text for the audio conversation associated with the display name local label = GetFilenameForAudioConversation(displayName)  -- Print the label text print(label)  // Get the vehicle in which the player is currently seated const vehicle = GetVehiclePedIsIn(PlayerPedId(), false);  // Get the model of the vehicle const model = GetEntityModel(vehicle);  // Get the display name of the vehicle model const displayName = GetDisplayNameFromVehicleModel(model);  // Get the label text for the audio conversation associated with the display name const label = GetFilenameForAudioConversation(displayName);  // Log the label text to the console console.log(label);  using static CitizenFX.Core.Native.API;  // Get the vehicle in which the player is currently seated Vehicle vehicle = GetVehiclePedIsIn(PlayerPedId(), false);  // Get the model of the vehicle uint model = (uint)GetEntityModel(vehicle);  // Get the display name of the vehicle model string displayName = GetDisplayNameFromVehicleModel(model);  // Get the label text for the audio conversation associated with the display name string label = GetFilenameForAudioConversation(displayName);  // Print the label text Debug.WriteLine(label);

### Parameters
* const char* labelName

### Return Value
* const char*

### Notes
* AP Hash: 0x0x95C4B5AD
* Build: 323
* Gets a localized string literal from a label name. Can be used for output of e.g. VEHICLE::GET_LIVERY_NAME. To check if a GXT label can be localized with this, HUD::DOES_TEXT_LABEL_EXIST can be used.

