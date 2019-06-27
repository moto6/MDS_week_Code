#include <grp.h>

int main(void) {
    struct group *grp;
    int n,m;

    for (n = 0; n < 3; n++) {
        grp = getgrent();
        printf("GroupName: %s, GID: %d ", grp->gr_name, (int)grp->gr_gid);

        m = 0;
        printf("Members : ");
        while (grp->gr_mem[m] != NULL)
            printf("%s ", grp->gr_mem[m++]);
        printf("\n");
    }

    return 0;
}
