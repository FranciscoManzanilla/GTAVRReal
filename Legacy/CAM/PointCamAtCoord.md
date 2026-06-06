# _POINT_CAM_AT_COORD

--- ns: CAM --- ## POINT_CAM_AT_COORD  // 0xF75497BB865F0803 0x914BC21A void POINT_CAM_AT_COORD(Cam cam, float x, float y, float z);   ## Parameters * **cam**: * **x**: * **y**: * **z**:  ## Examples local coords = vector3(402.99, -998.02, -99.00) local cam = CreateCamWithParams("DEFAULT_SCRIPTED_CAMERA", coords.x, coords.y, coords.z, 0.00, 0.00, 0.00, 50.00, false, 0) PointCamAtCoord(cam, coords.x, coords.y, coords.z)

### Parameters
* Cam cam
* float x
* float y
* float z

### Return Value
* void

### Notes
* AP Hash: 0x0x914BC21A
* Build: 323

