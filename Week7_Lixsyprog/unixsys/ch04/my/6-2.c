#include "myh.h"

int main() {

  pid_t pid;
  
  switch(pid = fork() ) {
    case -1 :
      perror("fork failed");
      exit(1);
      break;
    case 0 : 
      printf("im child PID : %d,  parent PID: %d,  ifchild: %d\n",(int)getpid(), (int)getppid(), (int)pid);
      break;

    default:
      printf("im parent, PID: %d,  parent PID : %d,  ifchild:%d \n",(int)getpid(), (int)getppid(), (int)pid);
      break; 
  }

  return 0;
}
