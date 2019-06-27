#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *val;

    val = getenv("SHELL");
    if (val == NULL)
        printf("SHELL not defined\n");
    else
        printf("1. SHELL = %s\n", val);

    setenv("SHELL","/usr/bin/csh", 0);
    val = getenv("SHELL");
    printf("2. SHELL = %s\n", val);

    setenv("SHELL","/usr/bin/csh", 1);
    val = getenv("SHELL");
    printf("3. SHELL = %s\n", val);

    return 0;
}
