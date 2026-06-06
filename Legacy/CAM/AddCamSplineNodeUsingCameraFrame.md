# _ADD_CAM_SPLINE_NODE_USING_CAMERA_FRAME

--- ns: CAM aliases: ["0x0A9F2A468B328E74"] --- ## ADD_CAM_SPLINE_NODE_USING_CAMERA_FRAME  // 0x0A9F2A468B328E74 0x30510511 void ADD_CAM_SPLINE_NODE_USING_CAMERA_FRAME(Cam cam, Cam cam2, int p2, int p3);   ## Parameters * **cam**: * **cam2**: * **p2**: * **p3**:

### Parameters
* Cam cam
* Cam cam2
* int length
* int p3

### Return Value
* void

### Notes
* AP Hash: 0x0x30510511
* Build: 323
* p0 is the spline camera to which the node is being added.
p1 is the camera used to create the node.
p3 is always 3 in scripts. It might be smoothing style or rotation order.

