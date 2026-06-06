# _GET_ROTATION_OF_VEHICLE_RECORDING_AT_TIME

--- ns: VEHICLE --- ## GET_ROTATION_OF_VEHICLE_RECORDING_AT_TIME  // 0x2058206FBE79A8AD 0xD96DEC68 cs_type(int) Vector3 GET_ROTATION_OF_VEHICLE_RECORDING_AT_TIME(int recording, float time, cs_type(AnyPtr) char* script);   ## Parameters * **recording**: * **time**: * **script**:  ## Return value

### Parameters
* int recording
* float time
* const char* script

### Return Value
* Vector3

### Notes
* AP Hash: 0x0xD96DEC68
* Build: 323
* This native does no interpolation between pathpoints. The same rotation will be returned for all times up to the next pathpoint in the recording.

See REQUEST_VEHICLE_RECORDING

