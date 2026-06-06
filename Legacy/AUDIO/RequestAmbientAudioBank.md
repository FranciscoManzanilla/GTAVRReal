# _REQUEST_AMBIENT_AUDIO_BANK

--- ns: AUDIO --- ## REQUEST_AMBIENT_AUDIO_BANK  // 0xFE02FFBED8CA9D99 0x23C88BC7 BOOL REQUEST_AMBIENT_AUDIO_BANK(char* bankName, BOOL bOverNetwork);  This native is marked as deprecated internally, please use [REQUEST_SCRIPT_AUDIO_BANK](#_0x2F844A8B08D76685)  This native has a new argument on newer game builds: * **playerBits**:  ## Parameters * **bankName**: * **bOverNetwork**:  ## Return value

### Parameters
* const char* audioBank
* BOOL p1
* Any p2

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x23C88BC7
* Build: 323
* All occurrences and usages found in b617d, sorted alphabetically and identical lines removed: https://pastebin.com/XZ1tmGEz
Full list of ambient audio bank names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/ambientAudioBankNames.json
p2 is always -1

