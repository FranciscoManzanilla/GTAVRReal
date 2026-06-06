# _SET_MULTIPLAYER_BANK_CASH

--- ns: HUD --- ## SET_MULTIPLAYER_BANK_CASH  // 0xDD21B55DF695CD0A 0x2C842D03 void SET_MULTIPLAYER_BANK_CASH();  Preview image:  ![](https://i.imgur.com/1BTmdyv.png)  To change the bank balance use [`STAT_SET_INT`](#_0xB3271D7AB655B441) with "BANK_BALANCE" to whatever value you need to.  ## Examples  // Code to show both Money and Bank HUD N_0x170f541e1cadd1de(true); SetMultiplayerWalletCash(); SetMultiplayerBankCash(); N_0x170f541e1cadd1de(false);  // Add a delay to let the player read his money await Delay(5000);  // Hide both Bank and Money HUD RemoveMultiplayerWalletCash(); RemoveMultiplayerBankCash();

### Return Value
* void

### Notes
* AP Hash: 0x0x2C842D03
* Build: 323

