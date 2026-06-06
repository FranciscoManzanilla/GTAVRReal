# _SET_PED_CAN_LOSE_PROPS_ON_DAMAGE

--- ns: PED aliases: ["0xE861D0B05C7662B8"] --- ## SET_PED_CAN_LOSE_PROPS_ON_DAMAGE  // 0xE861D0B05C7662B8 0x2F9550C2 void SET_PED_CAN_LOSE_PROPS_ON_DAMAGE(Ped ped, BOOL loseProps, int p2);  It makes the ped lose (or not lose) their props (like glasses or helmets/hat) when someone punches or pushes the ped. This is probably what's being used in GTA:O to keep players from knocking other player's hats/glasses off when in combat.  ## Parameters * **ped**: The target ped * **loseProps**: true = allow props to fall off, false = don't let props fall off * **p2**: purpose unknown, usually 0  ## Examples -- Make the ped NOT lose their props when they're hit or pushed. SetPedCanLosePropsOnDamage(PlayerPedId(), false, 0)  -- Make the ped LOSE their props when they're hit or pushed. SetPedCanLosePropsOnDamage(PlayerPedId(), true, 0)

### Parameters
* Ped ped
* BOOL toggle
* int p2

### Return Value
* void

### Notes
* AP Hash: 0x0x2F9550C2
* Build: 323

