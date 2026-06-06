# _GET_MOD_TEXT_LABEL

--- ns: VEHICLE --- ## GET_MOD_TEXT_LABEL  // 0x8935624F8C5592CC 0x0BA39CA7 char* GET_MOD_TEXT_LABEL(Vehicle vehicle, int modType, int modValue);  Returns the text label of a mod type for a given vehicle Use _GET_LABEL_TEXT to get the part name in the game's language  ## Parameters * **vehicle**: * **modType**: Refer to eVehicleModType in [`SET_VEHICLE_MOD`](#_0x6AF0636DDEDCB6DD). * **modValue**:  ## Return value

### Parameters
* Vehicle vehicle
* int modType
* int modValue

### Return Value
* const char*

### Notes
* AP Hash: 0x0x0BA39CA7
* Build: 323
* Returns the text label of a mod type for a given vehicle

Use GET_FILENAME_FOR_AUDIO_CONVERSATION to get the part name in the game's language

