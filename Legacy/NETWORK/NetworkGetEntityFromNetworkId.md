# _NETWORK_GET_ENTITY_FROM_NETWORK_ID

--- ns: NETWORK --- ## NETWORK_GET_ENTITY_FROM_NETWORK_ID  // 0xCE4E5D9B0A4FF560 0x5B912C3F Entity NETWORK_GET_ENTITY_FROM_NETWORK_ID(int netId); Get the local entity handle of the given network id  Through this native you can get back the entity that you previously converted to netid with [NetworkGetNetworkIdFromEntity](#_0x9E35DAB6) or with the `ToNet` natives  ## Parameters * **netId**: the network id of the entity  ## Return value The local entity handle of the network id  ## Examples local entity = NetworkGetEntityFromNetworkId(netId)  const entity = NetworkGetEntityFromNetworkId(netId);  int entity = NetworkGetEntityFromNetworkId(netId);

### Parameters
* int netId

### Return Value
* Entity

### Notes
* AP Hash: 0x0x5B912C3F
* Build: 323

