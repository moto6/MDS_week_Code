#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("PID : %d\n", (int)getpid());
    printf("PGID : %d\n", (int)getpgrp());
    printf("SID : %d\n", (int)getsid(0));

    return 0;
}
