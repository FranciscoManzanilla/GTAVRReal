# _GET_IS_WIDESCREEN

--- ns: GRAPHICS --- ## GET_IS_WIDESCREEN  // 0x30CF4BDA4FCB1905 0xEC717AEF BOOL GET_IS_WIDESCREEN();  This native retrieves whether the game is running in widescreen mode or not.  NativeDB Introduced: v323  ## Return value A boolean value indicating whether the game is running in widescreen mode (`true`) or not (`false`).  Returns `false` for narrow format aspect ratios (3:2, 4:3, 5:4, etc.) and `true` for wide format aspect ratios (5:3, 16:9, 16:10, etc.). If the aspect ratio is set to "Auto" in the game settings, it returns `false` or `true` based on the actual set resolution ratio.

### Return Value
* BOOL

### Notes
* AP Hash: 0x0xEC717AEF
* Build: 323
* Setting Aspect Ratio Manually in game will return:

false - for Narrow format Aspect Ratios (3:2, 4:3, 5:4, etc. )
true - for Wide format Aspect Ratios (5:3, 16:9, 16:10, etc. )

Setting Aspect Ratio to "Auto" in game will return "false" or "true" based on the actual set Resolution Ratio.

