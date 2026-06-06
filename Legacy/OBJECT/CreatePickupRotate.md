# _CREATE_PICKUP_ROTATE

--- ns: OBJECT --- ## CREATE_PICKUP_ROTATE  // 0x891804727E0A98B7 0xF015BFE2 Pickup CREATE_PICKUP_ROTATE(Hash pickupHash, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, int flag, int amount, Any p9, BOOL p10, Hash modelHash);  Pickup hashes: pastebin.com/8EuSv2r1 flags: 8 (1 << 3): place on ground 512 (1 << 9): spin around  ## Parameters * **pickupHash**: * **posX**: * **posY**: * **posZ**: * **rotX**: * **rotY**: * **rotZ**: * **flag**: * **amount**: * **p9**: * **p10**: * **modelHash**:  ## Return value

### Parameters
* Hash pickupHash
* float posX
* float posY
* float posZ
* float rotX
* float rotY
* float rotZ
* int flag
* int amount
* Any p9
* BOOL p10
* Hash modelHash

### Return Value
* Pickup

### Notes
* AP Hash: 0x0xF015BFE2
* Build: 323
* flags:
8 (1 << 3): place on ground
512 (1 << 9): spin around

Full list of pickup types by DurtyFree: https://github.com/DurtyFree/gta-v-data-dumps/blob/master/pickupTypes.json

