# _END_TEXT_COMMAND_THEFEED_POST_VERSUS_TU

--- ns: HUD aliases: ["0xB6871B0555B02996"] --- ## END_TEXT_COMMAND_THEFEED_POST_VERSUS_TU  // 0xB6871B0555B02996 0x5E93FBFA int END_TEXT_COMMAND_THEFEED_POST_VERSUS_TU(char* ch1TXD, char* ch1TXN, int val1, char* ch2TXD, char* ch2TXN, int val2);  NativeDB Added Parameter 7: int hudColorIndex1 NativeDB Added Parameter 8: int hudColorIndex2  ## Parameters * **ch1TXD**: * **ch1TXN**: * **val1**: * **ch2TXD**: * **ch2TXN**: * **val2**:  ## Return value

### Parameters
* const char* txdName1
* const char* textureName1
* int count1
* const char* txdName2
* const char* textureName2
* int count2
* int hudColor1
* int hudColor2

### Return Value
* int

### Notes
* AP Hash: 0x0x5E93FBFA
* Build: 323
* This function can show pictures of every texture that can be requested by REQUEST_STREAMED_TEXTURE_DICT.

List of picNames: https://pastebin.com/XdpJVbHz
HUD colors and their values: https://pastebin.com/d9aHPbXN

Shows a deathmatch score above the minimap, example: https://i.imgur.com/YmoMklG.png

