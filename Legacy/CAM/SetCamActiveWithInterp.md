# _SET_CAM_ACTIVE_WITH_INTERP

--- ns: CAM --- ## SET_CAM_ACTIVE_WITH_INTERP  // 0x9FBDA379383A52A4 0x7983E7F0 void SET_CAM_ACTIVE_WITH_INTERP(Cam camTo, Cam camFrom, int duration, int easeLocation, int easeRotation);  Previous declaration void SET_CAM_ACTIVE_WITH_INTERP(Cam camTo, Cam camFrom, int duration, BOOL easeLocation, BOOL easeRotation) is completely wrong. The last two params are integers not BOOLs...  ## Parameters * **camTo**: * **camFrom**: * **duration**: * **easeLocation**: * **easeRotation**:

### Parameters
* Cam camTo
* Cam camFrom
* int duration
* int easeLocation
* int easeRotation

### Return Value
* void

### Notes
* AP Hash: 0x0x7983E7F0
* Build: 323
* Previous declaration void SET_CAM_ACTIVE_WITH_INTERP(Cam camTo, Cam camFrom, int duration, BOOL easeLocation, BOOL easeRotation) is completely wrong. The last two params are integers not BOOLs...


