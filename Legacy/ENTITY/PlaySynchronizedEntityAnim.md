# _PLAY_SYNCHRONIZED_ENTITY_ANIM

--- ns: ENTITY --- ## PLAY_SYNCHRONIZED_ENTITY_ANIM  // 0xC77720A12FE14A86 0x012760AA BOOL PLAY_SYNCHRONIZED_ENTITY_ANIM(Entity entity, int syncedScene, char* animName, char* animDictName, float fBlendInDelta, float fBlendOutDelta, int iFlags, float fMoverBlendInDelta);  [Animations list](https://alexguirre.github.io/animations-list/)  ## Parameters * **entity**: The entity handle to play the animation on. * **syncedScene**: * **animName**: The name of the animation to play. * **animDictName**: The name of the animation dictionary to use. * **fBlendInDelta**: Blend in time. * **fBlendOutDelta**: Blend out time. * **iFlags**: The flags to use when playing the animation. See [`TASK_PLAY_ANIM`](#_0xEA47FE3719165B94). * **fMoverBlendInDelta**:  ## Return value

### Parameters
* Entity entity
* int syncedScene
* const char* animation
* const char* propName
* float p4
* float p5
* Any p6
* float p7

### Return Value
* BOOL

### Notes
* AP Hash: 0x0x012760AA
* Build: 323
* p4 and p7 are usually 1000.0f.

Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

