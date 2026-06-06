# _STOP_ANIM_TASK

--- ns: TASK --- ## STOP_ANIM_TASK  // 0x97FF36A1D40EA00A 0x2B520A57 void STOP_ANIM_TASK(Ped ped, char* animDictionary, char* animationName, float animExitSpeed);  [Animations list](https://alexguirre.github.io/animations-list/)  ## Parameters * **ped**: * **animDictionary**: * **animationName**: * **animExitSpeed**: Greater than `0.0`, higher is faster. Setting to `0.0` or using an integer, will cause animation lockout - requiring the animation to be played again or the player be killed.

### Parameters
* Entity entity
* const char* animDictionary
* const char* animationName
* float blendDelta

### Return Value
* void

### Notes
* AP Hash: 0x0x2B520A57
* Build: 323
* Full list of animation dictionaries and anims by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/animDictsCompact.json

