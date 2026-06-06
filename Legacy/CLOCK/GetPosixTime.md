# _GET_POSIX_TIME

--- ns: CLOCK --- ## GET_POSIX_TIME  // 0xDA488F299A5B164E 0xE15A5281 void GET_POSIX_TIME(int* year, int* month, int* day, int* hour, int* minute, int* second);  Gets system time as year, month, day, hour, minute and second. Example usage: int year; int month; int day; int hour; int minute; int second; TIME::GET_POSIX_TIME(&year, &month, &day, &hour, &minute, &second);  ## Parameters * **year**: * **month**: * **day**: * **hour**: * **minute**: * **second**:

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
* AP Hash: 0x0xE15A5281
* Build: 323
* Gets system time as year, month, day, hour, minute and second.

Example usage:

    int year;
 int month;
    int day;
  int hour;
 int minute;
   int second;

 TIME::GET_POSIX_TIME(&year, &month, &day, &hour, &minute, &second);


