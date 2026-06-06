# _PLAYSTATS_START_TRACKING_STUNTS

--- ns: STATS aliases: ["0x928DBFB892638EF3", "_PLAYSTATS_STUNT_PERFORMED_EVENT_ALLOW_TRIGGER"] --- ## PLAYSTATS_START_TRACKING_STUNTS  // 0x928DBFB892638EF3 void PLAYSTATS_START_TRACKING_STUNTS();  Allows stunts to be triggered and sent as a `CEventNetworkStuntPerformed` event.  Event types are shown below:  enum eTrackedStuntType { ST_FRONTFLIP = 0, ST_BACKFLIP = 1, ST_SPIN = 2, ST_WHEELIE = 3, ST_STOPPIE = 4, ST_BOWLING_PIN = 5, ST_FOOTBALL = 6, ST_ROLL = 7 };

### Return Value
* void

### Notes
* Build: 791
* Allows CEventNetworkStuntPerformed to be triggered.

