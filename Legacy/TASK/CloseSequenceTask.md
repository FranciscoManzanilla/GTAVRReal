# _CLOSE_SEQUENCE_TASK

--- ns: TASK --- ## CLOSE_SEQUENCE_TASK  // 0x39E72BC99E6360CB 0x1A7CEBD0 cs_type(Any) void CLOSE_SEQUENCE_TASK(int taskSequenceId);  For an example on how to use this please refer to [OPEN_SEQUENCE_TASK](#_0xE8854A4326B9E12B)  If you fail to call `CLOSE_SEQUENCE_TASK` and [`CLEAR_SEQUENCE_TASK`](#_0x3841422E9C488D8C) this can get stuck in a broken state until you restart your client.  ## Parameters * **taskSequenceId**: The task sequence to close

### Parameters
* int taskSequenceId

### Return Value
* void

### Notes
* AP Hash: 0x0x1A7CEBD0
* Build: 323

### Examples
#### Note
```note

```

