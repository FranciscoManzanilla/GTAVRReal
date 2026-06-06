# _PLAY_STREAM_FROM_OBJECT

--- ns: AUDIO --- ## PLAY_STREAM_FROM_OBJECT  // 0xEBAA9B64D76356FD 0xC5266BF7 void PLAY_STREAM_FROM_OBJECT(Object object);  Plays a preloaded stream back from the specified object.  ## Parameters * **object**:

### Parameters
* Object object

### Return Value
* void

### Notes
* AP Hash: 0x0xC5266BF7
* Build: 323
* Used with AUDIO::LOAD_STREAM

Example from finale_heist2b.c4:
TASK::TASK_SYNCHRONIZED_SCENE(l_4C8[2/*14*/], l_4C8[2/*14*/]._f7, l_30A, "push_out_vault_l", 4.0, -1.5, 5, 713, 4.0, 0);
                    PED::SET_SYNCHRONIZED_SCENE_PHASE(l_4C8[2/*14*/]._f7, 0.0);
                    PED::FORCE_PED_AI_AND_ANIMATION_UPDATE(l_4C8[2/*14*/], 0, 0);
                    PED::SET_PED_COMBAT_ATTRIBUTES(l_4C8[2/*14*/], 38, 1);
                    PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(l_4C8[2/*14*/], 1);
                    if (AUDIO::LOAD_STREAM("Gold_Cart_Push_Anim_01", "BIG_SCORE_3B_SOUNDS")) {
                        AUDIO::PLAY_STREAM_FROM_OBJECT(l_36F[0/*1*/]);
                    }

