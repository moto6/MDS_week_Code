#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat buf;
    int kind;

    stat("unix.txt", &buf);

    printf("Mode = %o (16Áø¼ö: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    kind = buf.st_mode & S_IFMT;
    printf("Kind = %x\n", kind);

    switch (kind) {
        case S_IFIFO:
            printf("unix.txt : FIFO\n");
            break;
        case S_IFDIR:
            printf("unix.txt : Directory\n");
            break;
        case S_IFREG:
            printf("unix.txt : Regular File\n");
            break;
    }

    return 0;
}
