# _GET_TIME_SINCE_LAST_DEATH

--- ns: PLAYER --- ## GET_TIME_SINCE_LAST_DEATH  // 0xC7034807558DDFCA 0x24BC5AC0 int GET_TIME_SINCE_LAST_DEATH();  Returns the time since the character died in (ms) milliseconds. example var time = Function.call<int>(Hash.GET_TIME_SINCE_LAST_DEATH(); UI.DrawSubtitle(time.ToString()); if player has not died, the int returned will be -1.  ## Return value

### Return Value
* int

### Notes
* AP Hash: 0x0x24BC5AC0
* Build: 323
* Returns the time since the character died in (ms) milliseconds.

example

var time = Function.call<int>(Hash.GET_TIME_SINCE_LAST_DEATH();

UI.DrawSubtitle(time.ToString());

if player has not died, the int returned will be -1.

