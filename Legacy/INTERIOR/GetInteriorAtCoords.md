# _GET_INTERIOR_AT_COORDS

--- ns: INTERIOR --- ## GET_INTERIOR_AT_COORDS  // 0xB0F7F8663821D9C3 0xA17FBF37 int GET_INTERIOR_AT_COORDS(float x, float y, float z);  Returns interior ID from specified coordinates. If coordinates are outside, then it returns 0. Example for VB.NET Dim interiorID As Integer = Native.Function.Call(Of Integer)(Hash.GET_INTERIOR_AT_COORDS, X, Y, Z)  ## Parameters * **x**: * **y**: * **z**:  ## Return value

### Parameters
* float x
* float y
* float z

### Return Value
* Interior

### Notes
* AP Hash: 0x0xA17FBF37
* Build: 323
* Returns interior ID from specified coordinates. If coordinates are outside, then it returns 0.

Example for VB.NET
Dim interiorID As Integer = Native.Function.Call(Of Integer)(Hash.GET_INTERIOR_AT_COORDS, X, Y, Z)

