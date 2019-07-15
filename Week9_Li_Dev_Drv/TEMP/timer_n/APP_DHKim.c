/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_BUFFER 26
char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER];

int main()
{
  int fd,i,mode;
  
  fd = open("/dev/mydrv",O_RDWR);
  printf("fd = %d\n",fd);

  if(fd == -1) {
  	printf("you are fail to open div files, if you success ...\n");
  	printf("mknod /dev/mydrv c 240 0\n");
  	exit(1);
  }

  for(i=0;i<10;i++) {
    write(fd,buf_out,MAX_BUFFER);
    printf("APP : write()\n");
    sleep(1);
  }

  close(fd);
  return (0);
}
