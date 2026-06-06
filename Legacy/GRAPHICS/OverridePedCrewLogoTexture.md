# _OVERRIDE_PED_CREW_LOGO_TEXTURE

No description available.

### Parameters
* Ped ped
* const char* txd
* const char* txn

### Return Value
* BOOL

### Notes
* Build: 877
* Overriding ped badge texture to a passed texture. It's synced between players (even custom textures!), don't forget to request used dict on *all* clients to make it sync properly. Can be removed by passing empty strings.

