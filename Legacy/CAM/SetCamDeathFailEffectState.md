# _SET_CAM_DEATH_FAIL_EFFECT_STATE

No description available.

### Parameters
* int p0

### Return Value
* void

### Notes
* AP Hash: 0x0xB06CCD38
* Build: 323
* if p0 is 0, effect is cancelled

if p0 is 1, effect zooms in, gradually tilts cam clockwise apx 30 degrees, wobbles slowly. Motion blur is active until cancelled.

if p0 is 2, effect immediately tilts cam clockwise apx 30 degrees, begins to wobble slowly, then gradually tilts cam back to normal. The wobbling will continue until the effect is cancelled.

