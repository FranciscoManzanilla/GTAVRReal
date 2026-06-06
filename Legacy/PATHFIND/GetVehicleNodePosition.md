# _GET_VEHICLE_NODE_POSITION

--- ns: PATHFIND --- ## GET_VEHICLE_NODE_POSITION  // 0x703123E5E7D429C2 0xE38E252D void GET_VEHICLE_NODE_POSITION(int nodeId, Vector3* outPosition);  Calling this with an invalid node id, will crash the game. Note that IS_VEHICLE_NODE_ID_VALID simply checks if nodeId is not zero. It does not actually ensure that the id is valid. Eg. IS_VEHICLE_NODE_ID_VALID(1) will return true, but will crash when calling GET_VEHICLE_NODE_POSITION().  ## Parameters * **nodeId**: * **outPosition**:

### Parameters
* int nodeId
* Vector3* outPosition

### Return Value
* void

### Notes
* AP Hash: 0x0xE38E252D
* Build: 323
* Calling this with an invalid node id, will crash the game.
Note that IS_VEHICLE_NODE_ID_VALID simply checks if nodeId is not zero. It does not actually ensure that the id is valid.
Eg. IS_VEHICLE_NODE_ID_VALID(1) will return true, but will crash when calling GET_VEHICLE_NODE_POSITION().

