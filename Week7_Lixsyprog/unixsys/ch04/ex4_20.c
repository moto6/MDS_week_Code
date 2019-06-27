#include <time.h>
#include <stdio.h>

int main(void) {
    struct tm tm;
    time_t t;

    time(&t);
    printf("Current Time(sec) : %d\n", (int)t);

    tm.tm_year = 109;
    tm.tm_mon = 11;
    tm.tm_mday = 31;
    tm.tm_hour = 12;
    tm.tm_min = 30;
    tm.tm_sec = 0;

    t = mktime(&tm);
    printf("2009/12/31 12:30:00 Time(sec) : %d\n", (int)t);

    return 0;
}
