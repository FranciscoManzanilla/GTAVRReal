# _THEFEED_AUTO_POST_GAMETIPS_OFF

--- ns: HUD aliases: ["0xADED7F5748ACAFE6","_THEFEED_SHOW_GTAO_TOOLTIPS", "_THEFEED_COMMENT_TELEPORT_POOL_OFF"] --- ## THEFEED_AUTO_POST_GAMETIPS_OFF  // 0xADED7F5748ACAFE6 0x1D6859CA void THEFEED_AUTO_POST_GAMETIPS_OFF();  Disables tip notifications enabled by [`THEFEED_AUTO_POST_GAMETIPS_ON`](#_0x56C8B608CFD49854)

### Return Value
* void

### Notes
* AP Hash: 0x0x1D6859CA
* Build: 323
* Displays "normal" notifications again after calling `THEFEED_AUTO_POST_GAMETIPS_ON` (those that were drawn before calling this native too), though those will have a weird offset and stay on screen forever (tested with notifications created from same script).

