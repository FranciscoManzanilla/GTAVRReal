# _SHUTDOWN_AND_LOAD_MOST_RECENT_SAVE

--- ns: NETWORK aliases: ["0x9ECA15ADFE141431"] --- ## _SHUTDOWN_AND_LOAD_MOST_RECENT_SAVE  // 0x9ECA15ADFE141431 BOOL _SHUTDOWN_AND_LOAD_MOST_RECENT_SAVE();  Disconnects you from the session, and starts loading single player, however you still remain connected to the server (only if you're the host, if you're not then you also (most likely) get disconnected from the server) and other players will not be able to join until you exit the game.  If you're already in SP then it'll re-load singleplayer.  You might need to DoScreenFadeIn and ShutdownLoadingScreen otherwise you probably won't end up loading into SP at all.  Somewhat related note: opening the pause menu after loading into this 'singleplayer' mode crashes the game.   ## Return value always seems to be 1

### Return Value
* BOOL

### Notes
* Build: 505
* In singleplayer this will re-load your game.

In FiveM / GTA:Online this disconnects you from the session, and starts loading single player, however you still remain connected to the server (only if you're the host, if you're not then you also (most likely) get disconnected from the server) and other players will not be able to join until you exit the game.

You might need to DoScreenFadeIn and ShutdownLoadingScreen otherwise you probably won't end up loading into SP at all.

Somewhat related note: opening the pause menu after loading into this 'singleplayer' mode crashes the game.

