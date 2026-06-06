# _DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE

--- ns: CAM aliases: ["_DISABLE_FIRST_PERSON_CAM_THIS_FRAME"] --- ## DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE  // 0xDE2EF5DA284CC8DF void DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE();  Disables first person camera while on foot for the current tick.

### Return Value
* void

### Notes
* Build: 323
* Disables first person camera for the current frame.

Found in decompiled scripts:
GRAPHICS::DRAW_DEBUG_TEXT_2D("Disabling First Person Cam", 0.5, 0.8, 0.0, 0, 0, 255, 255);
CAM::DISABLE_ON_FOOT_FIRST_PERSON_VIEW_THIS_UPDATE();

