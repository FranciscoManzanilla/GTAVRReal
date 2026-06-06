# _HAS_PC_CHEAT_WITH_HASH_BEEN_ACTIVATED

No description available.

### Parameters
* Hash hash

### Return Value
* BOOL

### Notes
* Build: 323
* Get inputted "Cheat code", for example:

while (TRUE)
{
    if (MISC::HAS_PC_CHEAT_WITH_HASH_BEEN_ACTIVATED(${fugitive}))
    {
       // Do something.
    }
    SYSTEM::WAIT(0);
}

Calling this will also set the last saved string hash to zero.


