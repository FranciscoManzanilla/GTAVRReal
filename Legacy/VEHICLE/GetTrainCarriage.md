# _GET_TRAIN_CARRIAGE

--- ns: VEHICLE --- ## GET_TRAIN_CARRIAGE  // 0x08AAFD0814722BC3 0x2544E7A6 Entity GET_TRAIN_CARRIAGE(Vehicle train, int trailerNumber);  Corrected p1. it's basically the 'carriage/trailer number'. So if the train has 3 trailers you'd call the native once with a var or 3 times with 1, 2, 3.  ## Parameters * **train**: * **trailerNumber**:  ## Return value

### Parameters
* Vehicle train
* int trailerNumber

### Return Value
* Vehicle

### Notes
* AP Hash: 0x0x2544E7A6
* Build: 323
* Corrected p1. it's basically the 'carriage/trailer number'. So if the train has 3 trailers you'd call the native once with a var or 3 times with 1, 2, 3.

