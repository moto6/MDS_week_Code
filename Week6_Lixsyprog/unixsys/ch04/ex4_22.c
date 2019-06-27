#include <time.h>
#include <stdio.h>

int main(void) {
    struct tm *tm;
    time_t t;

    time(&t);
    tm = localtime(&t);

    printf("Time(sec) : %d\n", (int)t);
    printf("Time(date) : %s\n", asctime(tm));

    return 0;
}
