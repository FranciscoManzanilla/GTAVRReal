# _SET_PED_TARGET_LOSS_RESPONSE

--- ns: PED --- ## SET_PED_TARGET_LOSS_RESPONSE  // 0x0703B9079823DA4A 0xCFA613FF void SET_PED_TARGET_LOSS_RESPONSE(Ped ped, int responseType);  Only 1 and 2 appear in the scripts. combatbehaviour.meta seems to only have TLR_SearchForTarget for all peds, but we don't know if that's 1 or 2.  ## Parameters * **ped**: * **responseType**:

### Parameters
* Ped ped
* int responseType

### Return Value
* void

### Notes
* AP Hash: 0x0xCFA613FF
* Build: 323
* enum eTargetLossResponseType
{
	TLR_ExitTask,
	TLR_NeverLoseTarget,
	TLR_SearchForTarget
};

