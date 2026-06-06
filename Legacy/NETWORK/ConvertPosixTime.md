# _CONVERT_POSIX_TIME

--- ns: NETWORK aliases: ["_GET_DATE_AND_TIME_FROM_UNIX_EPOCH"] --- ## CONVERT_POSIX_TIME  // 0xAC97AF97FA68E5D5 0xBB7CCE49 void CONVERT_POSIX_TIME(int posixTime, Any* timeStructure);  Takes the specified time and writes it to the structure specified in the second argument. struct date_time { alignas(8) int year; alignas(8) int month; alignas(8) int day; alignas(8) int hour; alignas(8) int minute; alignas(8) int second; };  ## Parameters * **posixTime**: * **timeStructure**:

### Parameters
* int posixTime
* Any* timeStructure

### Return Value
* void

### Notes
* AP Hash: 0x0xBB7CCE49
* Build: 323
* Takes the specified time and writes it to the structure specified in the second argument.

struct date_time
{
    int year;
    int PADDING1;
    int month;
    int PADDING2;
    int day;
    int PADDING3;
    int hour;
    int PADDING4;
    int minute;
    int PADDING5;
    int second;
    int PADDING6;
};

