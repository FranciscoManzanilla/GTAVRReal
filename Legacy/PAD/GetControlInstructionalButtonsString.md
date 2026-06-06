# _GET_CONTROL_INSTRUCTIONAL_BUTTONS_STRING

No description available.

### Parameters
* int control
* int action
* BOOL allowXOSwap

### Return Value
* const char*

### Notes
* Build: 323
* allowXOSwap appears to always be true.

EG:
GET_CONTROL_INSTRUCTIONAL_BUTTON (2, 201, 1) /*INPUT_FRONTEND_ACCEPT (e.g. Enter button)*/
GET_CONTROL_INSTRUCTIONAL_BUTTON (2, 202, 1) /*INPUT_FRONTEND_CANCEL (e.g. ESC button)*/
GET_CONTROL_INSTRUCTIONAL_BUTTON (2, 51, 1) /*INPUT_CONTEXT (e.g. E button)*/

gtaforums.com/topic/819070-c-draw-instructional-buttons-scaleform-movie/#entry1068197378

control: unused parameter

