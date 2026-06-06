# _HARD_ATTACH_CAM_TO_ENTITY

--- ns: CAM aliases: ["0x202A5ED9CE01D6E7"] --- ## HARD_ATTACH_CAM_TO_ENTITY  // 0x202A5ED9CE01D6E7 void HARD_ATTACH_CAM_TO_ENTITY(Cam cam, Entity entity, float xRot, float yRot, float zRot, float xOffset, float yOffset, float zOffset, BOOL isRelative);  Attaches a camera to an entity, including full matrix transformations for both rotation and position offsets. NativeDB Introduced: v2189  ## Parameters * **cam**: The camera handle. * **entity**: The entity handle. * **xRot**: X-axis rotation. * **yRot**: Y-axis rotation. * **zRot**: Z-axis rotation. * **xOffset**: X-axis offset * **yOffset**: Y-axis offset * **zOffset**: Z-axis offset * **isRelative**: Whether or not the camera position will be relative to the entity rotation  ## Examples  -- assuming that the obj variable was created earlier in the script local cam = CreateCam("DEFAULT_SCRIPTED_CAMERA", true)  -- attaches the camera to the object rotated 90 degrees and offset 10 x values HardAttachCamToEntity(cam, obj, 0.0, 0.0, 90.0, 10.0, 0.0, 0.0, true)  -- renders the camera RenderScriptCams(true, false, 0, true, true)   // assuming that the obj variable was created earlier in the script const cam = CreateCam("DEFAULT_SCRIPTED_CAMERA", true)  // attaches the camera to the object rotated 90 degrees and offset 10 x values HardAttachCamToEntity(cam, obj, 0.0, 0.0, 90.0, 10.0, 0.0, 0.0, true)  // renders the camera RenderScriptCams(true, false, 0, true, true)  using static CitizenFX.Core.Native.API;  // assuming that the obj variable was created earlier in the script int cam = CreateCam("DEFAULT_SCRIPTED_CAMERA", true);  // attaches the camera to the object rotated 90 degrees and offset 10 x values HardAttachCamToEntity(cam, obj, 0.0f, 0.0f, 90.0f, 10.0f, 0.0f, 0.0f, true);  // renders the camera RenderScriptCams(true, false, 0, true, true);

### Parameters
* Cam cam
* Entity entity
* float xRot
* float yRot
* float zRot
* float xOffset
* float yOffset
* float zOffset
* BOOL isRelative

### Return Value
* void

### Notes
* Build: 2189
* Example from am_mp_drone script: 

CAM::HARD_ATTACH_CAM_TO_ENTITY(Local_190.f_169, NETWORK::NET_TO_OBJ(Local_190.f_159), 0f, 0f, 180f, Var0, 1);

