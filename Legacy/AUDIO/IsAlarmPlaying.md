# _IS_ALARM_PLAYING

--- ns: AUDIO --- ## IS_ALARM_PLAYING  // 0x226435CB96CCFC8C 0x9D8E1D23 BOOL IS_ALARM_PLAYING(char* alarmName);  ## Parameters * **alarmName**:  ## Return value Returns true if an alarm is currently playing with the specified name  ## Examples local bAlarmPlaying = IsAlarmPlaying("PORT_OF_LS_HEIST_FORT_ZANCUDO_ALARMS")

### Parameters
* const char* alarmName

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x9D8E1D23
* Build: 323
* Example:

bool playing = AUDIO::IS_ALARM_PLAYING("PORT_OF_LS_HEIST_FORT_ZANCUDO_ALARMS");
Full list of alarm names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/alarmSounds.json

