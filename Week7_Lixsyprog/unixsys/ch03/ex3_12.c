#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char buf[BUFSIZ];

    realpath("unix.sym", buf);
    printf("unix.sym : REALPATH = %s\n", buf);

    return 0;
}
