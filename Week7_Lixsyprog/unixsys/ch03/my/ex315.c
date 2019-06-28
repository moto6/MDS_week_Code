#include "myh.h"
#include <dirent.h>

#include <stdlib.h>
int main(void)
{
  DIR *dp;
  struct dirent *dent;

  if((dp = opendir("hanbit")) == NULL ) {
      perror("opedir : habit");
      printf("fail\n");
      exit(1);
  }

  while((dent == readdir(dp))) {
    printf("Name : %s", dent->d_name);
    printf("Inode : %d\n", (int)dent->d_ino);
  }

  closedir(dp);


  return 0;

}
