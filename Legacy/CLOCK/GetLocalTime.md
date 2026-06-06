# _GET_LOCAL_TIME

--- ns: CLOCK --- ## GET_LOCAL_TIME  // 0x50C7A99057A69748 0x124BCFA2 void GET_LOCAL_TIME(int* year, int* month, int* day, int* hour, int* minute, int* second);  Gets local system time as year, month, day, hour, minute and second. Example usage: int year; int month; int day; int hour; int minute; int second; or use std::tm struct TIME::GET_LOCAL_TIME(&year, &month, &day, &hour, &minute, &second);  ## Parameters * **year**: * **month**: * **day**: * **hour**: * **minute**: * **second**:

### Parameters
* int* year
* int* month
* int* day
* int* hour
* int* minute
* int* second

### Return Value
* void

### Notes
* AP Hash: 0x0x124BCFA2
* Build: 323
* Gets local system time as year, month, day, hour, minute and second.

Example usage:

int year;
int month;
int day;
int hour;
int minute;
int second;
or use std::tm struct

TIME::GET_LOCAL_TIME(&year, &month, &day, &hour, &minute, &second);


