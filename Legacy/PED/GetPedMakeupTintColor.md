# _GET_PED_MAKEUP_TINT_COLOR

No description available.

### Parameters
* int makeupColorIndex
* int* outR
* int* outG
* int* outB

### Return Value
* void

### Notes
* Build: 323
* Input: Makeup color index, value between 0 and 63 (inclusive).
Output: RGB values for the makeup color specified in the input.

This is used with the makeup color swatches scaleform.
Use `GET_PED_HAIR_TINT_COLOR` to get the hair colors.

