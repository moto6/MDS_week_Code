#include <sys/systeminfo.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char buf[257];

    if (sysinfo(SI_HW_SERIAL, buf, 257) == -1) {
        perror("sysinfo");
        exit(1);
    }
    printf("HW Serial : %s\n", buf);

    if (sysinfo(SI_ISALIST, buf, 257) == -1) {
        perror("sysinfo");
        exit(1);
    }
    printf("ISA List : %s\n", buf);

    return 0;
}
