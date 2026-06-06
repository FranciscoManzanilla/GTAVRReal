# _TASK_SYNCHRONIZED_SCENE

--- ns: TASK --- ## TASK_SYNCHRONIZED_SCENE  // 0xEEA929141F699854 0x4F217E7B void TASK_SYNCHRONIZED_SCENE(Ped ped, int scene, char* animDictionary, char* animationName, float speed, float speedMultiplier, int duration, int flag, float playbackRate, Any p9);  TASK::TASK_SYNCHRONIZED_SCENE(ped, scene, "creatures@rottweiler@in_vehicle@std_car", "get_in", 1000.0, -8.0, 4, 0, 0x447a0000, 0);  ## Parameters * **ped**: * **scene**: * **animDictionary**: * **animationName**: * **speed**: * **speedMultiplier**: * **duration**: * **flag**: * **playbackRate**: * **p9**:

### Parameters
* Ped ped
* int scene
* const char* animDictionary
* const char* animationName
* float blendIn
* float blendOut
* int flags
* int ragdollBlockingFlags
* float moverBlendDelta
* int ikFlags

### Return Value
* void

### Notes
* AP Hash: 0x0x4F217E7B
* Build: 323
*  TASK::TASK_SYNCHRONIZED_SCENE(ped, scene, "creatures@rottweiler@in_vehicle@std_car", "get_in", 1000.0, -8.0, 4, 0, 0x447a0000, 0);

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

