# _SET_VEHICLE_MODEL_IS_SUPPRESSED

--- ns: VEHICLE --- ## SET_VEHICLE_MODEL_IS_SUPPRESSED  // 0x0FC2D89AC25A5814 0x42A08C9B void SET_VEHICLE_MODEL_IS_SUPPRESSED(Hash model, BOOL suppressed);  seems to make the vehicle stop spawning naturally in traffic. Here's an essential example: VEHICLE::SET_VEHICLE_MODEL_IS_SUPPRESSED(GAMEPLAY::GET_HASH_KEY("taco"), true);  ## Parameters * **model**: * **suppressed**:

### Parameters
* Hash model
* BOOL suppressed

### Return Value
* void

### Notes
* AP Hash: 0x0x42A08C9B
* Build: 323
* Makes the vehicle stop spawning naturally in traffic. Here's an essential example:

VEHICLE::SET_VEHICLE_MODEL_IS_SUPPRESSED(MISC::GET_HASH_KEY("taco"), true);

Full list of vehicles by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/vehicles.json

