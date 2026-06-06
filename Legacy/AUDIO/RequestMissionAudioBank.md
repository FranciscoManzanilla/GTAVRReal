# _REQUEST_MISSION_AUDIO_BANK

--- ns: AUDIO --- ## REQUEST_MISSION_AUDIO_BANK  // 0x7345BDD95E62E0F2 0x916E37CA BOOL REQUEST_MISSION_AUDIO_BANK(char* bankName, BOOL bOverNetwork);  This native is marked as deprecated internally, please use [REQUEST_SCRIPT_AUDIO_BANK](#_0x2F844A8B08D76685)  This native has a new argument on newer game builds: * **playerBits**:  ## Parameters * **bankName**: * **bOverNetwork**:  ## Return value

### Parameters
* const char* audioBank
* BOOL p1
* Any p2

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x916E37CA
* Build: 323
* All occurrences and usages found in b617d: https://pastebin.com/NzZZ2Tmm
Full list of mission audio bank names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/missionAudioBankNames.json
p2 is always -1

