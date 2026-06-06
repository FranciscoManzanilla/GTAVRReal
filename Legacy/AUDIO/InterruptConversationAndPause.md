# _INTERRUPT_CONVERSATION_AND_PAUSE

--- ns: AUDIO aliases: ["0x8A694D7A68F8DC38"] --- ## INTERRUPT_CONVERSATION_AND_PAUSE  // 0x8A694D7A68F8DC38 0xDD4A3F1F void INTERRUPT_CONVERSATION_AND_PAUSE(Ped interrupterPed, char* context, char* voiceName);  Handles conversation interrupts and pauses, using the code-side system for improved timing and to minimize unfriendly logic interactions.  ## Parameters * **interrupterPed**: the ped speaking * **context**: the line to use * **voiceName**: the voicename for the audio asset

### Parameters
* Ped ped
* const char* p1
* const char* speaker

### Return Value
* void

### Notes
* AP Hash: 0x0xDD4A3F1F
* Build: 323
* One call found in the b617d scripts:

AUDIO::INTERRUPT_CONVERSATION_AND_PAUSE(NETWORK::NET_TO_PED(l_3989._f26F[0/*1*/]), "CONV_INTERRUPT_QUIT_IT", "LESTER");

