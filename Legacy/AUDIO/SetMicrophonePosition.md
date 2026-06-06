# _SET_MICROPHONE_POSITION

--- ns: AUDIO --- ## SET_MICROPHONE_POSITION  // 0xB6AE90EDDE95C762 0xAD7BB191 void SET_MICROPHONE_POSITION(BOOL p0, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);  If this is the correct name, what microphone? I know your TV isn't going to reach out and adjust your headset so..  ## Parameters * **p0**: * **x1**: * **y1**: * **z1**: * **x2**: * **y2**: * **z2**: * **x3**: * **y3**: * **z3**:

### Parameters
* BOOL toggle
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* float x3
* float y3
* float z3

### Return Value
* void

### Notes
* AP Hash: 0x0xAD7BB191
* Build: 323
* This native controls where the game plays audio from. By default the microphone is positioned on the player.
When p0 is true the game will play audio from the 3 positions inputted.
It is recommended to set all 3 positions to the same value as mixing different positions doesn't seem to work well.
The scripts mostly use it with only one position such as in fbi3.c: 
AUDIO::SET_MICROPHONE_POSITION(true, ENTITY::GET_ENTITY_COORDS(iLocal_3091, true), ENTITY::GET_ENTITY_COORDS(iLocal_3091, true), ENTITY::GET_ENTITY_COORDS(iLocal_3091, true));

