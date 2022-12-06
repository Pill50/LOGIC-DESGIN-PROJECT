#include "clock.h"

char second=30, minute=2, hour=17, day=12, date=12, month=12, year=22;
void Set_Time()
{
    write_ds1307(ADDRESS_SECOND, second);
    write_ds1307(ADDRESS_MINUTE, minute);
    write_ds1307(ADDRESS_HOUR, hour);
    write_ds1307(ADDRESS_DAY, day);
    write_ds1307(ADDRESS_DATE, date);
    write_ds1307(ADDRESS_MONTH, month);
    write_ds1307(ADDRESS_YEAR, year);
}
void Read_time(){
    second  = read_ds1307(ADDRESS_SECOND);
    minute = read_ds1307(ADDRESS_MINUTE);
    hour = read_ds1307(ADDRESS_HOUR);
    day = read_ds1307(ADDRESS_DAY);
    date = read_ds1307(ADDRESS_DATE);
    month = read_ds1307(ADDRESS_MONTH);
    year = read_ds1307(ADDRESS_YEAR); 
}
