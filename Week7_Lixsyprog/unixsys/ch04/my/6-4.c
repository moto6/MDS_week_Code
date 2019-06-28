#include "myh.h"

int main() {

  printf("Before Exec Func \n");
  if(execlp("ls", "ls", "-a", (char *)NULL) == -1) {
    perror("execlp");
    exit(1);
  }

  printf("--> After exec function \n");

  return 0;
}


