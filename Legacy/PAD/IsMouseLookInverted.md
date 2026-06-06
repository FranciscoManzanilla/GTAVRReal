# _IS_MOUSE_LOOK_INVERTED

No description available.

### Return Value
* BOOL

### Notes
* Build: 323
* Used with IS_LOOK_INVERTED() and negates its affect.

--

Not sure how the person above got that description, but here's an actual example:

if (PAD::IS_USING_KEYBOARD_AND_MOUSE(2)) {
    if (a_5) {
        if (PAD::IS_LOOK_INVERTED()) {
            a_3 *= -1;
        }
        if (PAD::IS_MOUSE_LOOK_INVERTED()) {
            a_3 *= -1;
        }
    }
}

