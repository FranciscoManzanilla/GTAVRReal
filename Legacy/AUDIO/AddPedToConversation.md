# _ADD_PED_TO_CONVERSATION

--- ns: AUDIO --- ## ADD_PED_TO_CONVERSATION  // 0x95D9F4BC443956E7 0xF8D5EB86 void ADD_PED_TO_CONVERSATION(int speakerConversationIndex, Ped ped, char* voiceName);   ## Parameters * **speakerConversationIndex**: * **ped**: * **voiceName**:

### Parameters
* int index
* Ped ped
* const char* p2

### Return Value
* void

### Notes
* AP Hash: 0x0xF8D5EB86
* Build: 323
* 4 calls in the b617d scripts. The only one with p0 and p2 in clear text:

AUDIO::ADD_PED_TO_CONVERSATION(5, l_AF, "DINAPOLI");

=================================================
One of the 2 calls in dialogue_handler.c p0 is in a while-loop, and so is determined to also possibly be 0 - 15.

