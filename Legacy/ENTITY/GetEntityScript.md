# _GET_ENTITY_SCRIPT

--- ns: ENTITY --- ## GET_ENTITY_SCRIPT  // 0xA6E9C38DB51D7748 0xB7F70784 char* GET_ENTITY_SCRIPT(Entity entity, ScrHandle* script);  All ambient entities in-world seem to have the same value for the second argument (Any *script), depending on when the scripthook was activated/re-activated. I've seen numbers from ~5 to almost 70 when the value was translated with to_string. The function return value seems to always be 0.  ## Parameters * **entity**: * **script**:  ## Return value

### Parameters
* Entity entity
* ScrHandle* script

### Return Value
* const char*

### Notes
* AP Hash: 0x0xB7F70784
* Build: 323
* Returns the name of the script that owns/created the entity or nullptr. Second parameter is unused, can just be a nullptr.

