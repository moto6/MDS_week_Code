#include "myh.h"

extern int errno;

int main(void) {
  int per;	
  if(access("unix.bak", F_OK) == -1 && errno == ENOENT) {
    printf("unix.bak : File is not exist!\n");
  }
  per = access("unix.txt", R_OK);
  if(per == 0) {
    printf("nuix.txt : Read Permission is permitted! \n");
  }
  else if(per == -1 && errno == EACCES) {
    printf("unix.txt : Read perminssion is not permitted \n");
  }


  return 0;
}
