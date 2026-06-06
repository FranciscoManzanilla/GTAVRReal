# _FIND_ANIM_EVENT_PHASE

--- ns: ENTITY --- ## FIND_ANIM_EVENT_PHASE  // 0x07F1BE2BCCAA27A7 0xC41DDA62 BOOL FIND_ANIM_EVENT_PHASE(char* animDictionary, char* animName, char* p2, Any* p3, Any* p4);  In the script "player_scene_t_bbfight.c4": "if (ENTITY::FIND_ANIM_EVENT_PHASE(&l_16E, &l_19F[v_4/*16*/], v_9, &v_A, &v_B))" -- &l_16E (p0) is requested as an anim dictionary earlier in the script. -- &l_19F[v_4/*16*/] (p1) is used in other natives in the script as the "animation" param. -- v_9 (p2) is instantiated as "victim_fall"; I'm guessing that's another anim --v_A and v_B (p3 & p4) are both set as -1.0, but v_A is used immediately after this native for: "if (v_A < ENTITY::GET_ENTITY_ANIM_CURRENT_TIME(...))" Both v_A and v_B are seemingly used to contain both Vector3's and floats, so I can't say what either really is other than that they are both output parameters. p4 looks more like a *Vector3 though -alphazolam  [Animations list](https://alexguirre.github.io/animations-list/)  ## Parameters * **animDictionary**: * **animName**: * **p2**: * **p3**: * **p4**:  ## Return value

### Parameters
* const char* animDictionary
* const char* animName
* const char* p2
* Any* p3
* Any* p4

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xC41DDA62
* Build: 323
* In the script "player_scene_t_bbfight.c4":
"if (ENTITY::FIND_ANIM_EVENT_PHASE(&l_16E, &l_19F[v_4/*16*/], v_9, &v_A, &v_B))"
-- &l_16E (p0) is requested as an anim dictionary earlier in the script.
-- &l_19F[v_4/*16*/] (p1) is used in other natives in the script as the "animation" param.
-- v_9 (p2) is instantiated as "victim_fall"; I'm guessing that's another anim
--v_A and v_B (p3 & p4) are both set as -1.0, but v_A is used immediately after this native for: 
"if (v_A < ENTITY::GET_ENTITY_ANIM_CURRENT_TIME(...))"
Both v_A and v_B are seemingly used to contain both Vector3's and floats, so I can't say what either really is other than that they are both output parameters. p4 looks more like a *Vector3 though

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

