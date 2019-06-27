#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
    struct stat buf;

    stat("unix.txt", &buf);
    printf("Mode = %o (16Áø¼ö: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    if ((buf.st_mode & S_IREAD) != 0)
        printf("unix.txt : user has a read permission\n");

    if ((buf.st_mode & (S_IREAD >> 3)) != 0)
        printf("unix.txt : group has a read permission\n");

    if ((buf.st_mode & S_IROTH) != 0)
        printf("unix.txt : other have a read permission\n");

    return 0;
}
