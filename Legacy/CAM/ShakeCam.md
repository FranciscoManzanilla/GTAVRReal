# _SHAKE_CAM

--- ns: CAM --- ## SHAKE_CAM  // 0x6A25241C340D3822 0x1D4211B0 void SHAKE_CAM(Cam cam, char* shakeName, float intensity);  See [`SHAKE_GAMEPLAY_CAM`](#_0xFD55E49555E017CF) for a full list of camera shakes.  ## Parameters * **cam**: The camera handle. * **shakeName**: The name of the shake. * **intensity**: The intensity of the shake.

### Parameters
* Cam cam
* const char* type
* float amplitude

### Return Value
* void

### Notes
* AP Hash: 0x0x1D4211B0
* Build: 323
* Possible shake types (updated b617d):

DEATH_FAIL_IN_EFFECT_SHAKE
DRUNK_SHAKE
FAMILY5_DRUG_TRIP_SHAKE
HAND_SHAKE
JOLT_SHAKE
LARGE_EXPLOSION_SHAKE
MEDIUM_EXPLOSION_SHAKE
SMALL_EXPLOSION_SHAKE
ROAD_VIBRATION_SHAKE
SKY_DIVING_SHAKE
VIBRATE_SHAKE

Full list of cam shake types by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/camShakeTypesCompact.json

