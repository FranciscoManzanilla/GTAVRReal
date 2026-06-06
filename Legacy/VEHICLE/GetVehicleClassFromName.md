# _GET_VEHICLE_CLASS_FROM_NAME

--- ns: VEHICLE --- ## GET_VEHICLE_CLASS_FROM_NAME  // 0xDEDF1C8BD47C2200 0xEA469980 int GET_VEHICLE_CLASS_FROM_NAME(Hash modelHash);  For a full enum, see here : pastebin.com/i2GGAjY0 char buffer[128]; std::sprintf(buffer, "VEH_CLASS_%i", VEHICLE::GET_VEHICLE_CLASS_FROM_NAME (hash)); const char* className = HUD::_GET_LABEL_TEXT(buffer);  ## Parameters * **modelHash**:  ## Return value

### Parameters
* Hash modelHash

### Return Value
* int

### Notes
* AP Hash: 0x0xEA469980
* Build: 323
* char buffer[128];
std::sprintf(buffer, "VEH_CLASS_%i", VEHICLE::GET_VEHICLE_CLASS_FROM_NAME (hash));

const char* className = HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION(buffer);

Full list of vehicles by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/vehicles.json

