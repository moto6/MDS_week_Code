#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    if (mknod("HAN-FIFO", S_IFIFO | 0644, 0) == -1) {
        perror("mknod");
        exit(1);
    }

    if (mkfifo("BIT-FIFO", 0644) == -1) {
        perror("mkfifo");
        exit(1);
    }

    return 0;
}
