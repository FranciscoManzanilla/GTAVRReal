# _TERRAINGRID_SET_PARAMS

--- ns: GRAPHICS aliases: ["0x1C4FC5752BCD8E48"] --- ## TERRAINGRID_SET_PARAMS  // 0x1C4FC5752BCD8E48 0x3B637AA7 void TERRAINGRID_SET_PARAMS(float x, float y, float z, float p3, float rotation, float p5, float width, float height, float p8, float scale, float glowIntensity, float normalHeight, float heightDiff);  This native is used along with these two natives: [`TERRAINGRID_ACTIVATE`](#_0xA356990E161C9E65) and [`TERRAINGRID_SET_COLOURS`](#_0x5CE62918F8D703C7).  This native configures the location, size, rotation, normal height, and the difference ratio between min, normal and max.  All those natives combined they will output something like this: https://i.imgur.com/TC6cku6.png  ## Parameters * **x**: Grid center x coord. * **y**: Grid center y coord. * **z**: Grid center z coord. * **p3**: Not sure, but seems to be the amount of lines top/bottom there are in the grid. -1.0 works best. * **rotation**: Grid rotation (keep between 0.0 and 1.0). * **p5**: Offset top/bottom (? not sure about this one, seems weird). * **width**: Grid width (usually 15.0). * **height**: Grid height (usually 15.0). * **p8**: Not sure, but seems to be the amount of lines left/right there are in the grid. -1.0 works best. * **scale**: Zoom / scale (higher values = smaller (more) squares) (lower values = bigger (less) squares). * **glowIntensity**: glow intensity / opacity (40.0 is fine for daylight, 15.0 is fine for night time). * **normalHeight**: The z coord for 'normal' height (white grid lines level). * **heightDiff**: This is the height difference/margin used for line color changes. 0.2 works fine (normalHeight + 0.2 = yellow, normalHeight - 0.2 = red).  ## Examples N_0xa356990e161c9e65(true); // toggle on/off  // this native configures the location, size, rotation, normal height, and the difference ratio between min, normal and max. N_0x1c4fc5752bcd8e48(-1114.121f, 220.789f, 63.78f, -1f, 0.85f, 0f, 15f, 15f, -1f, 20f, 40f, 63.78f, 0.2f);  // This native defines the colors (and alpha/opacity levels) for min, normal and max heights. // (in this case: red for lower, white for normal, yellow for higher) N_0x5ce62918f8d703c7(255, 0, 0, 64, 255, 255, 255, 5, 255, 255, 0, 64);

### Parameters
* float x
* float y
* float z
* float forwardX
* float forwardY
* float forwardZ
* float sizeX
* float sizeY
* float sizeZ
* float gridScale
* float glowIntensity
* float normalHeight
* float heightDiff

### Return Value
* void

### Notes
* AP Hash: 0x0x3B637AA7
* Build: 323
* This native is used along with these two natives: `TERRAINGRID_ACTIVATE` and `TERRAINGRID_SET_COLOURS`.
This native configures the location, size, rotation, normal height, and the difference ratio between min, normal and max.

All those natives combined they will output something like this: https://i.imgur.com/TC6cku6.png

This native renders a box at the given position, with a special shader that renders a grid on world geometry behind it. This box does not have backface culling.
The forward args here are a direction vector, something similar to what's returned by GET_ENTITY_FORWARD_VECTOR.
normalHeight and heightDiff are used for positioning the color gradient of the grid, colors specified via TERRAINGRID_SET_COLOURS.

Example with box superimposed on the image to demonstrate: https://i.imgur.com/wdqskxd.jpg

