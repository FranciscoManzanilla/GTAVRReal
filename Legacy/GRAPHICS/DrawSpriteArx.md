# _DRAW_SPRITE_ARX

No description available.

### Parameters
* const char* textureDict
* const char* textureName
* float x
* float y
* float width
* float height
* float p6
* int red
* int green
* int blue
* int alpha
* Any p11
* Any p12

### Return Value
* void

### Notes
* Build: 1290
* Used in arcade games and Beam hack minigame in Doomsday Heist. I will most certainly dive into this to try replicate arcade games.
x position must be between 0.0 and 1.0 (1.0 being the most right side of the screen)
y position must be between 0.0 and 1.0 (1.0 being the most bottom side of the screen)
width 0.0 - 1.0 is the reasonable amount generally
height 0.0 - 1.0 is the reasonable amount generally
p6 almost always 0.0
p11 seems to be unknown but almost always 0 int

