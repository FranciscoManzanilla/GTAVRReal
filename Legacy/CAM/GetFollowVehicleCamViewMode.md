# _GET_FOLLOW_VEHICLE_CAM_VIEW_MODE

--- ns: CAM --- ## GET_FOLLOW_VEHICLE_CAM_VIEW_MODE  // 0xA4FF579AC0E3AAAE 0xA4B4DB03 int GET_FOLLOW_VEHICLE_CAM_VIEW_MODE();  See [`GET_FOLLOW_PED_CAM_VIEW_MODE`](#_0x8D4D46230B2C353A) for the follow mode enum.  ## Return value

### Return Value
* int

### Notes
* AP Hash: 0x0xA4B4DB03
* Build: 323
* Returns the type of camera:

enum _viewmode //0xA11D7CA8
{
	THIRD_PERSON_NEAR = 0,
	THIRD_PERSON_MEDIUM = 1,
	THIRD_PERSON_FAR = 2,
	CINEMATIC = 3,
	FIRST_PERSON = 4
};

