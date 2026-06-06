# _REQUEST_SCRIPT_AUDIO_BANK

--- ns: AUDIO --- ## REQUEST_SCRIPT_AUDIO_BANK  // 0x2F844A8B08D76685 0x21322887 BOOL REQUEST_SCRIPT_AUDIO_BANK(char* bankName, BOOL bOverNetwork);  This native has a new argument on newer game builds: * **playerBits**:  ## Parameters * **bankName**: * **bOverNetwork**:  ## Return value Requests and returns true/false if the script audio bank has laoded

### Parameters
* const char* audioBank
* BOOL p1
* Any p2

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x21322887
* Build: 323
* All occurrences and usages found in b617d, sorted alphabetically and identical lines removed: https://pastebin.com/AkmDAVn6
Full list of script audio bank names by DurtyFree https://github.com/DurtyFree/gta-v-data-dumps/blob/master/scriptAudioBankNames.json
p2 is always -1

