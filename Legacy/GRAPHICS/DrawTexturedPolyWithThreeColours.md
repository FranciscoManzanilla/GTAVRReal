# _DRAW_TEXTURED_POLY_WITH_THREE_COLOURS

No description available.

### Parameters
* float x1
* float y1
* float z1
* float x2
* float y2
* float z2
* float x3
* float y3
* float z3
* float red1
* float green1
* float blue1
* int alpha1
* float red2
* float green2
* float blue2
* int alpha2
* float red3
* float green3
* float blue3
* int alpha3
* const char* textureDict
* const char* textureName
* float u1
* float v1
* float w1
* float u2
* float v2
* float w2
* float u3
* float v3
* float w3

### Return Value
* void

### Notes
* Build: 877
* Used for drawling Deadline trailing lights, see deadline.ytd

Each vertex has its own colour that is blended/illuminated on the texture. Additionally, the R, G, and B components are floats that are int-casted internally.
For UVW mapping (u,v,w parameters), reference your favourite internet resource for more details.

