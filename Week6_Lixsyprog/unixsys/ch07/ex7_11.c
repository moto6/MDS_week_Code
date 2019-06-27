#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void handler(int signo) {
    char *s;

    s = strsignal(signo);
    printf("Received Signal : %s\n", s);
}

int main(void) {
    if (sigset(SIGINT, handler) == SIG_ERR) {
        perror("sigset");
        exit(1);
    }

    sighold(SIGINT);

    pause();

    return 0;
}
