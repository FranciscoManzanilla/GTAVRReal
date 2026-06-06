# _FORCE_USE_AUDIO_GAME_OBJECT

--- ns: AUDIO aliases: ["0x4F0C413926060B38","_SET_VEHICLE_AUDIO", "_FORCE_VEHICLE_ENGINE_AUDIO"] --- ## FORCE_USE_AUDIO_GAME_OBJECT  // 0x4F0C413926060B38 0x33B0B007 void FORCE_USE_AUDIO_GAME_OBJECT(Vehicle vehicle, char* gameObjectName);  This native sets the audio to the specific vehicle hash's audioNameHash.  ## Parameters * **vehicle**: * **gameObjectName**:

### Parameters
* Vehicle vehicle
* const char* audioName

### Return Value
* void

### Notes
* AP Hash: 0x0x33B0B007
* Build: 323
* This native sets the audio of the specified vehicle to the audioName (p1).

Use the audioNameHash found in vehicles.meta

Example:
_SET_VEHICLE_AUDIO(veh, "ADDER");
The selected vehicle will now have the audio of the Adder.

