# _SET_RAIN

No description available.

### Parameters
* float intensity

### Return Value
* void

### Notes
* Build: 323
* With an `intensity` higher than `0.5f`, only the creation of puddles gets faster, rain and rain sound won't increase after that.
With an `intensity` of `0.0f` rain and rain sounds are disabled and there won't be any new puddles.
To use the rain intensity of the current weather, call this native with `-1f` as `intensity`.

