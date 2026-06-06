# _PREPARE_ALARM

--- ns: AUDIO --- ## PREPARE_ALARM  // 0x9D74AE343DB65533 0x084932E8 BOOL PREPARE_ALARM(char* alarmName);  Prepares any banks required to play the given alarm  ## Parameters * **alarmName**:  ## Return value Returns true if the alarm was successfully prepared

### Parameters
* const char* alarmName

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x084932E8
* Build: 323
* Example:

bool prepareAlarm = AUDIO::PREPARE_ALARM("PORT_OF_LS_HEIST_FORT_ZANCUDO_ALARMS");
Full list of alarm names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/alarmSounds.json

