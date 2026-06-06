# _INTERRUPT_CONVERSATION

--- ns: AUDIO --- ## INTERRUPT_CONVERSATION  // 0xA018A12E5C5C2FA6 0xF3A67AF3 void INTERRUPT_CONVERSATION(Ped interrupterPed, cs_type(AnyPtr) char* context, cs_type(AnyPtr) char* voiceName);  Handles conversation interrupts, using the code-side system for improved timing and to minimize unfriendly logic interactions.  ## Parameters * **interrupterPed**: the ped speaking * **context**: the line to use * **voiceName**: the voicename for the audio asset

### Parameters
* Ped ped
* const char* voiceline
* const char* speaker

### Return Value
* void

### Notes
* AP Hash: 0x0xF3A67AF3
* Build: 323
* Example from carsteal3.c: AUDIO::INTERRUPT_CONVERSATION(PLAYER::PLAYER_PED_ID(), "CST4_CFAA", "FRANKLIN");
Voicelines can be found in GTAV\x64\audio\sfx in files starting with "SS_" which seems to mean scripted speech.

