#include <sys/systeminfo.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[257];

    if (sysinfo(SI_HOSTNAME, buf, 257) == -1) {
        perror("sysinfo");
        exit(1);
    }
    printf("Before Hostname : %s\n", buf);

    strcpy(buf, "hbooks");
    if (sysinfo(SI_SET_HOSTNAME, buf, 257) == -1) {
        perror("sysinfo");
        exit(1);
    }

    if (sysinfo(SI_HOSTNAME, buf, 257) == -1) {
        perror("sysinfo");
        exit(1);
    }
    printf("After Hostname : %s\n", buf);

    return 0;
}
