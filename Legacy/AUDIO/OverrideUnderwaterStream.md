# _OVERRIDE_UNDERWATER_STREAM

--- ns: AUDIO --- ## OVERRIDE_UNDERWATER_STREAM  // 0xF2A9CDABCEA04BD6 0x9A083B7E void OVERRIDE_UNDERWATER_STREAM(cs_type(AnyPtr) char* streamName, BOOL override);  This native allows a scripter to override the current underwater stream. It needs to be called before going into the water  It needs to also be called with OVERRIDE_UNDERWATER_STREAM("", false) in order to stop overriding.  ## Parameters * **streamName**: * **override**:

### Parameters
* const char* p0
* BOOL p1

### Return Value
* void

### Notes
* AP Hash: 0x0x9A083B7E
* Build: 323

