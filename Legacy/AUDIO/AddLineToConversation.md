# _ADD_LINE_TO_CONVERSATION

--- ns: AUDIO --- ## ADD_LINE_TO_CONVERSATION  // 0xC5EF963405593646 0x96CD0513 void ADD_LINE_TO_CONVERSATION(int speakerConversationIndex, char* context, char* subtitle, int listenerNumber, int volumeType, BOOL isRandom, BOOL interruptible, BOOL ducksRadio, BOOL ducksScore, int audibility, BOOL headset, BOOL dontInterruptForSpecialAbility, BOOL isPadSpeakerRoute);  enum eAudibility { AUD_AUDIBILITY_NORMAL = 0, AUD_AUDIBILITY_CLEAR = 1, AUD_AUDIBILITY_CRITICAL = 2, AUD_AUDIBILITY_LEAD_IN = 3 }  ## Parameters * **speakerConversationIndex**: * **context**: * **subtitle**: * **listenerNumber**: * **volumeType**: * **isRandom**: * **interruptible**: * **ducksRadio**: * **ducksScore**: * **audibility**: See eAudibility * **headset**: * **dontInterruptForSpecialAbility**: * **isPadSpeakerRoute**:

### Parameters
* int index
* const char* p1
* const char* p2
* int p3
* int p4
* BOOL p5
* BOOL p6
* BOOL p7
* BOOL p8
* int p9
* BOOL p10
* BOOL p11
* BOOL p12

### Return Value
* void

### Notes
* AP Hash: 0x0x96CD0513
* Build: 323
* NOTE: ones that are -1, 0 - 35 are determined by a function where it gets a TextLabel from a global then runs,
GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME and depending on what the result is it goes in check order of 0 - 9 then A - Z then z (lowercase). So it will then return 0 - 35 or -1 if it's 'z'. The func to handle that ^^ is func_67 in dialog_handler.c atleast in TU27 Xbox360 scripts.

p0 is -1, 0 - 35
p1 is a char or string (whatever you wanna call it)
p2 is Global 10597 + i * 6. 'i' is a while(i < 70) loop
p3 is again -1, 0 - 35 
p4 is again -1, 0 - 35 
p5 is either 0 or 1 (bool ?)
p6 is either 0 or 1 (The func to determine this is bool)
p7 is either 0 or 1 (The func to determine this is bool)
p8 is either 0 or 1 (The func to determine this is bool)
p9 is 0 - 3 (Determined by func_60 in dialogue_handler.c)
p10 is either 0 or 1 (The func to determine this is bool)
p11 is either 0 or 1 (The func to determine this is bool)
p12 is unknown as in TU27 X360 scripts it only goes to p11.

