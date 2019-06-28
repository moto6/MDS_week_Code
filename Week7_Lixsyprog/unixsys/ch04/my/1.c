#include "myh.h"

int main(void) {
  struct utsname uts;

  if(uname(&uts) == -1 ) {
    perror("uname");
    exit(1);

  }


  printf("OS name  : %s\n",uts.sysname);
  printf("Nodename  : %s\n",uts.nodename);
  printf("Relase  : %s\n",uts.release);
  printf("Version  : %s\n",uts.version);
  printf("Machine  : %s\n",uts.machine);

  return 0;

}


