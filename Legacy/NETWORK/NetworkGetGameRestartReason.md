# __NETWORK_GET_GAME_RESTART_REASON

No description available.

### Return Value
* int

### Notes
* Build: 3323
* enum eNetworkGameRestartReason
{
	BE_RESTART_SERVICE_NOT_RUNNING = 1, 	// BattlEye service not running
	BE_RESTART_SERVICE_NEEDS_UPDATE, 		// BattlEye service needs an update
	BE_RESTART_UNKNOWN_REASON,				// Unknown BattlEye reason
	BE_RESTART_EF_DISABLED_WITH_BE,			// BattlEye Enforcement Flag is disabled, but BattlEye is active
	BE_RESTART_EF_ENABLED_NO_BE,			// BattlEye Enforcement Flag is enabled, but BattlEye is not active
	BE_RESTART_BE_MODULES_FAILED_TO_LOAD,	// BattlEye modules failed to load
	NUM_NETWORK_GAME_RESTART_REASONS
};

