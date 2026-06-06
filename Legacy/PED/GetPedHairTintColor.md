# _GET_PED_HAIR_TINT_COLOR

No description available.

### Parameters
* int hairColorIndex
* int* outR
* int* outG
* int* outB

### Return Value
* void

### Notes
* Build: 323
* Input: Haircolor index, value between 0 and 63 (inclusive).
Output: RGB values for the haircolor specified in the input.

This is used with the hair color swatches scaleform.
Use `GET_PED_MAKEUP_TINT_COLOR` to get the makeup colors.

