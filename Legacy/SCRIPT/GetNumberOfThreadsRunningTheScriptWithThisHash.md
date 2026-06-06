# _GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH

No description available.

### Parameters
* Hash scriptHash

### Return Value
* int

### Notes
* AP Hash: 0x0x029D3841
* Build: 323
* Gets the number of instances of the specified script is currently running.

Actually returns numRefs - 1.
if (program)
	v3 = rage::scrProgram::GetNumRefs(program) - 1;
return v3;

