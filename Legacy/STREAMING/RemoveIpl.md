# _REMOVE_IPL

--- ns: STREAMING --- ## REMOVE_IPL  // 0xEE6C5AD3ECE0A82D 0xDF7CBD36 void REMOVE_IPL(char* iplName);  IPL list can be found [here](https://gist.github.com/4mmonium/4c8a076b5f712a7cc64666003009a2e7).  ## Parameters * **iplName**:

### Parameters
* const char* iplName

### Return Value
* void

### Notes
* AP Hash: 0x0xDF7CBD36
* Build: 323
* Removes an IPL from the map.

Full list of IPLs and interior entity sets by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/ipls.json

Example:
C#:
Function.Call(Hash.REMOVE_IPL, "trevorstrailertidy");

C++:
STREAMING::REMOVE_IPL("trevorstrailertidy");

iplName = Name of IPL you want to remove.

