# _DISABLE_OCCLUSION_THIS_FRAME

--- ns: GRAPHICS aliases: ["0x3669F1B198DCAA4F"] --- ## DISABLE_OCCLUSION_THIS_FRAME  // 0x3669F1B198DCAA4F 0x0DCC0B8B void DISABLE_OCCLUSION_THIS_FRAME();  This disables all occluders that cause the 'flickering' rendering under the map and inside buildings with no interiors, note that this may impact performance on lower end systems.  ## Examples -- Example thread that has to run every frame Citizen.CreateThread(function() while true do DisableOcclusionThisFrame() Citizen.Wait(0) end end)

### Return Value
* void

### Notes
* AP Hash: 0x0x0DCC0B8B
* Build: 323

