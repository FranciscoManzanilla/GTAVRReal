# _PREFETCH_SRL

--- ns: STREAMING --- ## PREFETCH_SRL  // 0x3D245789CE12982C 0x37BE2FBB void PREFETCH_SRL(char* srl);  This native is used to attribute the SRL that BeginSrl is going to load. This is usually used for 'in-game' cinematics (not cutscenes but camera stuff) instead of SetFocusArea because it loads a specific area of the map which is pretty useful when the camera moves from distant areas. For instance, GTA:O opening cutscene.  https://pastebin.com/2EeKVeLA : a list of SRL found in srllist.meta https://pastebin.com/zd9XYUWY : here is the content of a SRL file opened with codewalker.  ## Parameters * **srl**: A SRL name.  ## Examples  PrefetchSrl('GTAO_INTRO_MALE') while not IsSrlLoaded() do Citizen.Wait(100) end BeginSrl()

### Parameters
* const char* srl

### Return Value
* void

### Notes
* AP Hash: 0x0x37BE2FBB
* Build: 323
* This native is used to attribute the SRL that BEGIN_SRL is going to load. This is usually used for 'in-game' cinematics (not cutscenes but camera stuff) instead of SET_FOCUS_POS_AND_VEL because it loads a specific area of the map which is pretty useful when the camera moves from distant areas.
For instance, GTA:O opening cutscene.
https://pastebin.com/2EeKVeLA : a list of SRL found in srllist.meta
https://pastebin.com/zd9XYUWY here is the content of a SRL file opened with codewalker.

