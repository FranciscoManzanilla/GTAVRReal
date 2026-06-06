# _SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE

No description available.

### Parameters
* float p0
* float distance

### Return Value
* void

### Notes
* AP Hash: 0x0x77340650
* Build: 323
* Seems to animate the gameplay camera zoom.

Eg. SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE(1f, 1000f);
will animate the camera zooming in from 1000 meters away.

Game scripts use it like this:

// Setting this to 1 prevents V key from changing zoom
PLAYER::SET_PLAYER_FORCED_ZOOM(PLAYER::PLAYER_ID(), 1);

// These restrict how far you can move cam up/down left/right
CAM::SET_THIRD_PERSON_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(-20f, 50f);
CAM::SET_THIRD_PERSON_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(-60f, 0f);

CAM::SET_THIRD_PERSON_CAM_ORBIT_DISTANCE_LIMITS_THIS_UPDATE(1f, 1f);

