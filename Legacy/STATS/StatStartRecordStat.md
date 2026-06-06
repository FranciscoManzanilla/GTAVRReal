# _STAT_START_RECORD_STAT

No description available.

### Parameters
* int statType
* int valueType

### Return Value
* BOOL

### Notes
* Build: 463
* enum StatTrackingType
{
	LongestWheelie = 1,
	LongestStoppie = 2,
	NoCrashes = 3,
	HighestSpeed = 4,
	_MostFlips = 5,
	_LongestSpin = 6,
	_HighestJumpReached = 7,
	LongestJump = 8,
	_NearMissesNoCrash = 9,
	LongestFallSurvived = 10,
	LowestParachute = 11,
	ReverseDriving = 12,
	LongestFreefall = 13,
	VehiclesStolen = 14,
	_SomeCFireEventCount = 15,
	_Unk16 = 16,
	_LowFlyingTime = 17,
	LowFlying = 18,
	_InvertedFlyingTime = 19,
	InvertedFlying = 20,
	_PlaneSpinCount = 21,
	MeleeKills = 22, // Players
	_LongestSniperKill = 23,
	SniperSkills = 24, // Players
	DrivebyKills = 25, // Players
	HeadshotKills = 26, // Players
	LongestBail = 27,
	_TotalRammedByCar = 28,
	NearMissesPrecise = 29,
	_FreefallTime = 30,
	Unk31 = 31,
}

enum StatTrackingValueType
{
	Total,
	Max,
	Min
}

