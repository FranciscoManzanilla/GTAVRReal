# _DRAW_SPRITE_ARX_WITH_UV

No description available.

### Parameters
* const char* textureDict
* const char* textureName
* float x
* float y
* float width
* float height
* float u1
* float v1
* float u2
* float v2
* float heading
* int red
* int green
* int blue
* int alpha
* Any p15

### Return Value
* void

### Notes
* Build: 1868
* Similar to DRAW_SPRITE, but allows to specify the texture coordinates used to draw the sprite.

u1, v1 - texture coordinates for the top-left corner
u2, v2 - texture coordinates for the bottom-right corner

