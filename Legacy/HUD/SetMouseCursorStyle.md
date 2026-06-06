# _SET_MOUSE_CURSOR_STYLE

--- ns: HUD aliases: ["0x8DB8CFFD58B62552","_SET_CURSOR_SPRITE", "_SET_MOUSE_CURSOR_SPRITE"] --- ## SET_MOUSE_CURSOR_STYLE  // 0x8DB8CFFD58B62552 void SET_MOUSE_CURSOR_STYLE(int style);  Changes the mouse style.  enum eMousePointerStyle { ARROW = 1, ARROW_DIMMED = 2, HAND_OPEN = 3, HAND_GRAB = 4, HAND_MIDDLE_FINGER = 5, ARROW_LEFT = 6, ARROW_RIGHT = 7, ARROW_UP = 8, ARROW_DOWN = 9, ARROW_TRIMMING = 10, ARROW_PLUS = 11, ARROW_MINUS = 12 };  ## Parameters * **style**: Which sprite to change to, see declared enum `eMousePointerStyle`.

### Parameters
* int spriteId

### Return Value
* void

### Notes
* Build: 323
* Changes the mouse cursor's sprite. 
1 = Normal
6 = Left Arrow
7 = Right Arrow

