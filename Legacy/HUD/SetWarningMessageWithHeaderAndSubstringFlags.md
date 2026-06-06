# _SET_WARNING_MESSAGE_WITH_HEADER_AND_SUBSTRING_FLAGS

--- ns: HUD aliases: ["_SET_WARNING_MESSAGE_3"] --- ## SET_WARNING_MESSAGE_WITH_HEADER_AND_SUBSTRING_FLAGS  // 0x701919482C74B5AB 0x749929D3 void SET_WARNING_MESSAGE_WITH_HEADER_AND_SUBSTRING_FLAGS(char* entryHeader, char* entryLine1, Any instructionalKey, char* entryLine2, BOOL p4, Any p5, Any p6, Any* p7, Any* p8, BOOL p9);  You can only use text entries. No custom text.  NativeDB Added Parameter 11: Any p10  ## Parameters * **entryHeader**: * **entryLine1**: * **instructionalKey**: * **entryLine2**: * **p4**: * **p5**: * **p6**: * **p7**: * **p8**: * **p9**:

### Parameters
* const char* entryHeader
* const char* entryLine1
* int instructionalKey
* const char* entryLine2
* BOOL p4
* Any p5
* Any additionalIntInfo
* const char* additionalTextInfoLine1
* const char* additionalTextInfoLine2
* BOOL showBackground
* int errorCode

### Return Value
* void

### Notes
* AP Hash: 0x0x749929D3
* Build: 323
* You can use this native for custom input, without having to use any scaleform-related natives.
The native must be called on tick.
The entryHeader must be a valid label.
For Single lines use JL_INVITE_N as entryLine1, JL_INVITE_ND for multiple.
Notes:
- additionalIntInfo: replaces first occurrence of ~1~ in provided label with an integer
- additionalTextInfoLine1: replaces first occurrence of ~a~ in provided label, with your custom text
- additionalTextInfoLine2: replaces second occurrence of ~a~ in provided label, with your custom text
- showBackground: shows black background of the warning screen
- errorCode: shows an error code at the bottom left if nonzero
Example of usage:
SET_WARNING_MESSAGE_WITH_HEADER_AND_SUBSTRING_FLAGS("ALERT", "JL_INVITE_ND", 66, "", true, -1, -1, "Testing line 1", "Testing line 2", true, 0);
Screenshot:
https://imgur.com/a/IYA7vJ8

