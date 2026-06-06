# _REQUEST_MODEL

--- ns: STREAMING --- ## REQUEST_MODEL  // 0x963D27A58DF860AC 0xFFF1B500 void REQUEST_MODEL(Hash model);  Request a model (archetype) to be loaded for use by the current script. Use SET\_MODEL\_AS\_NO\_LONGER\_NEEDED when done using the model in script.  ## Parameters * **model**: The model to request.  ## Examples local modelHash = `adder` RequestModel(modelHash) while not HasModelLoaded(modelHash) do Wait(0) end  -- omitted: creating a vehicle  -- when done using the model SetModelAsNoLongerNeeded(modelHash)

### Parameters
* Hash model

### Return Value
* void

### Notes
* AP Hash: 0x0xFFF1B500
* Build: 323
* Request a model to be loaded into memory.


