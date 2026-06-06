# _DISABLE_INTERIOR

--- ns: INTERIOR --- ## DISABLE_INTERIOR  // 0x6170941419D7D8EC 0x093ADEA5 void DISABLE_INTERIOR(int interiorID, BOOL toggle);  Example: This removes the interior from the strip club and when trying to walk inside the player just falls: INTERIOR::DISABLE_INTERIOR(118018, true);  ## Parameters * **interiorID**: * **toggle**:

### Parameters
* Interior interior
* BOOL toggle

### Return Value
* void

### Notes
* AP Hash: 0x0x093ADEA5
* Build: 323
* Example: 
This removes the interior from the strip club and when trying to walk inside the player just falls:

INTERIOR::DISABLE_INTERIOR(118018, true);

