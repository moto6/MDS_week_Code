#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[256];
    int len, ns;

    ns = atoi(argv[1]);

    strcpy(buf, "Welcome to Server, from Bit");
    if ((send(ns, buf, strlen(buf) + 1, 0)) == -1) {
        perror("send");
        exit(1);
    }

    if ((len=recv(ns, buf, strlen(buf), 0)) == -1) {
        perror("recv");
        exit(1);
    }
    printf("@@ [Bit] From Client: %s\n", buf);
    close(ns);

    return 0;
}
