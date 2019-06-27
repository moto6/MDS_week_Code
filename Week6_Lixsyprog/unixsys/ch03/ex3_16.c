#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    DIR *dp;
    struct dirent *dent;
    struct stat sbuf;
    char path[BUFSIZ];

    if ((dp = opendir("hanbit")) == NULL) {
        perror("opendir: hanbit");
        exit(1);
    }

    while ((dent = readdir(dp))) {
       if (dent->d_name[0] == '.') continue;
       else break;
    }

    sprintf(path, "hanbit/%s", dent->d_name);
    stat(path, &sbuf);

    printf("Name : %s\n", dent->d_name);
    printf("Inode(dirent) : %d\n", (int)dent->d_ino);
    printf("Inode(stat) : %d\n", (int)sbuf.st_ino);
    printf("Mode : %o\n", (unsigned int)sbuf.st_mode);
    printf("Uid : %d\n", (int)sbuf.st_uid);

    closedir(dp);

    return 0;
}
