# _GET_DISPLAY_NAME_FROM_VEHICLE_MODEL

--- ns: VEHICLE --- ## GET_DISPLAY_NAME_FROM_VEHICLE_MODEL  // 0xB215AAC32D25D019 0xEC86DF39 char* GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(Hash modelHash);  Returns the display name/text label (`gameName` in `vehicles.meta`) for the specified vehicle model.  ## Parameters * **modelHash**: A vehicle model to check.  ## Return value The display name for the vehicle, or `'CARNOTFOUND'` if invalid.

### Parameters
* Hash modelHash

### Return Value
* const char*

### Notes
* AP Hash: 0x0xEC86DF39
* Build: 323
* Returns model name of vehicle in all caps. Needs to be displayed through localizing text natives to get proper display name.
-----------------------------------------------------------------------------------------------------------------------------------------
While often the case, this does not simply return the model name of the vehicle (which could be hashed to return the model hash). Variations of the same vehicle may also use the same display name.
-----------------------------------------------------------------------------------------------------------------------------------------

Returns "CARNOTFOUND" if the hash doesn't match a vehicle hash.

Using HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION, you can get the localized name.

Full list of vehicles by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/vehicles.json

