# _GET_FRAME_TIME

--- ns: MISC --- ## GET_FRAME_TIME  // 0x15C40837039FFAF7 0x96374262 float GET_FRAME_TIME();  Gets the high precision frame time of the last frame in seconds.  _note: the example above is way less precise._  ## Return value The frame time (in seconds) of the last frame.  ## Examples local time1 = GetGameTimer() Citizen.Wait(0)  -- Prints for example 0.01253530010581 at around 90 FPS print(GetFrameTime())  -- This would print about the same as above, but is less accurate, ie: 0.012 print((GetGameTimer() - time1) / 1000)

### Return Value
* float

### Notes
* AP Hash: 0x0x96374262
* Build: 323

