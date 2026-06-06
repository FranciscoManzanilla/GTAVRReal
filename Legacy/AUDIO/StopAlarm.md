# _STOP_ALARM

--- ns: AUDIO --- ## STOP_ALARM  // 0xA1CADDCD98415A41 0xF987BE8C void STOP_ALARM(char* alarmName, BOOL instantStop);   ## Parameters * **alarmName**: * **instantStop**: Whether to kill the alarm instantly, or to let the audio system turn it off when it becomes inaudible

### Parameters
* const char* alarmName
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0xF987BE8C
* Build: 323
* Example:

This will stop the alarm at Fort Zancudo.

AUDIO::STOP_ALARM("PORT_OF_LS_HEIST_FORT_ZANCUDO_ALARMS", 1);

First parameter (char) is the name of the alarm.
Second parameter (bool) has to be true (1) to have any effect.
Full list of alarm names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/alarmSounds.json

