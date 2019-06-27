#include <stdio.h>

int main(void) {
    FILE *fp;

    fp = tmpfile();

    fputs("unix system", fp);

    fclose(fp);

    return 0;
}
