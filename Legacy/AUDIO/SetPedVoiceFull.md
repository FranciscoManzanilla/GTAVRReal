# _SET_PED_VOICE_FULL

--- ns: AUDIO aliases: ["0x40CF0D12D142A9E8", "_SET_PED_SCREAM"] --- ## SET_PED_VOICE_FULL  // 0x40CF0D12D142A9E8 void SET_PED_VOICE_FULL(Ped ped);  Calls the same internal function [`_SET_PED_VOICE_GROUP`](#_0x7CDC8C3B89F661B3) calls, but passes `voiceGroupHash` (defined as a parameter in the referenced native) as `0`.  ## Parameters * **ped**:

### Parameters
* Ped ped

### Return Value
* void

### Notes
* Build: 323
* Assigns some ambient voice to the ped.

