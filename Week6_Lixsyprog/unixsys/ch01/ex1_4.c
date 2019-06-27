#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    if (access("unix.txt", R_OK) == -1) {
        perror("unix.txt");
        exit(1);
    }

    return 0;
}
