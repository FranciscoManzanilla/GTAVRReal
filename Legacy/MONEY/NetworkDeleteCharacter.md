# _NETWORK_DELETE_CHARACTER

--- ns: MONEY --- ## NETWORK_DELETE_CHARACTER  // 0x05A50AF38947EB8D 0xA9F7E9C3 void NETWORK_DELETE_CHARACTER(int characterSlot, BOOL p1, BOOL p2);  Note the 2nd parameters are always 1, 0. I have a feeling it deals with your money, wallet, bank. So when you delete the character it of course wipes the wallet cash at that time. So if that was the case, it would be eg, NETWORK_DELETE_CHARACTER(characterIndex, deleteWalletCash, deleteBankCash);  ## Parameters * **characterSlot**: * **p1**: * **p2**:

### Parameters
* int characterSlot
* BOOL p1
* BOOL p2

### Return Value
* void

### Notes
* AP Hash: 0x0xA9F7E9C3
* Build: 323
* Note the 2nd parameters are always 1, 0. I have a feeling it deals with your money, wallet, bank. So when you delete the character it of course wipes the wallet cash at that time. So if that was the case, it would be eg, NETWORK_DELETE_CHARACTER(characterIndex, deleteWalletCash, deleteBankCash);

