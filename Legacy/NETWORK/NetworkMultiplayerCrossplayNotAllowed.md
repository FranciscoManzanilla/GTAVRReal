# __NETWORK_MULTIPLAYER_CROSSPLAY_NOT_ALLOWED

No description available.

### Return Value
* BOOL

### Notes
* Build: 3504
* For the XboxPC version this returns true if XPRIVILEGE_MULTIPLAYER_SESSIONS is granted but XPRIVILEGE_CROSS_PLAY is NOT granted.
For more information, see https://learn.microsoft.com/en-us/gaming/gdk/_content/gc/live/features/identity/privileges/concepts/live-user-privileges-client#privilege-ids-to-check

Always returns false for non-XboxPC versions.

