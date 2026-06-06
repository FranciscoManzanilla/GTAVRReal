# _SET_PED_ALTERNATE_MOVEMENT_ANIM

--- ns: PED --- ## SET_PED_ALTERNATE_MOVEMENT_ANIM  // 0x90A43CC281FFAB46 0xBA84FD8C void SET_PED_ALTERNATE_MOVEMENT_ANIM(Ped ped, int stance, char* animDictionary, char* animationName, float p4, BOOL p5);  stance: 0 = idle 1 = walk 2 = running p5 = usually set to true  [Animations list](https://alexguirre.github.io/animations-list/)  ## Parameters * **ped**: * **stance**: * **animDictionary**: * **animationName**: * **p4**: * **p5**:

### Parameters
* Ped ped
* int stance
* const char* animDictionary
* const char* animationName
* float p4
* BOOL p5

### Return Value
* void

### Notes
* AP Hash: 0x0xBA84FD8C
* Build: 323
* stance:
0 = idle
1 = walk
2 = running

p5 = usually set to true

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

Full list of movement clipsets by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/movementClipsetsCompact.json

