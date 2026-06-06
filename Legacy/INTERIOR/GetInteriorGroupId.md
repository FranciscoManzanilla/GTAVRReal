# _GET_INTERIOR_GROUP_ID

--- ns: INTERIOR --- ## GET_INTERIOR_GROUP_ID  // 0xE4A84ABF135EF91A 0x09D6376F int GET_INTERIOR_GROUP_ID(int interior);  Returns the group ID of the specified interior. For example, regular interiors have group 0, subway interiors have group 1. There are a few other groups too.  ## Parameters * **interior**:  ## Return value

### Parameters
* Interior interior

### Return Value
* int

### Notes
* AP Hash: 0x0x09D6376F
* Build: 323
* Returns the group ID of the specified interior.
0 = default
1 = subway station, subway tracks, sewers
3 = train tunnel under mirror park
5 = tunnel near del perro
6 = train tunnel near chilliad
7 = train tunnel near josiah
8 = train tunnel in sandy shores
9 = braddock tunnel (near chilliad)
12 = tunnel under fort zancudo
14 = train tunnel under cypress flats
18 = rockford plaza parking garage
19 = arcadius parking garage
20 = union depository parking garage
21 = fib parking garage

