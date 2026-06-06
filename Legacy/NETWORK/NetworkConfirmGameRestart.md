# __NETWORK_CONFIRM_GAME_RESTART

No description available.

### Return Value
* void

### Notes
* Build: 3323
* If the restart reason is 4 (BE_RESTART_EF_DISABLED_WITH_BE), will cause the game to exit with exit code 622011. Otherwise exits with code 622010. Has no effect when a restart hasn't been requested (reason == 0 or reason > 6).

Note that this 'confirmation' itself does not restart the game, a call to QUIT_GAME or similar is required afterwards.

