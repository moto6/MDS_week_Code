/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_BUFFER 26
char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER];

int main()
{
  int fd,i,mode,pid;
  pid = getpid();
  printf("pid is : %d\n",pid );
  fd = open("/dev/mydrv",O_RDWR);
  printf("fd = %d\n",fd);

  if(fd == -1) {
  	printf("you are fail to open div files, if you success ...\n");
  	printf("mknod /dev/mydrv c 240 0\n");
  	exit(1);
  }

  printf("APP : Read Func\n");
  read(fd,buf_in,MAX_BUFFER);
  printf("APP : Read() -> buf_in = %s\n",buf_in);
  

  printf("APP : Write Func\n");
  for(i = 0;i < MAX_BUFFER;i++)
     buf_out[i] = 'a' + i;
  write(fd,buf_out,MAX_BUFFER);
  printf("APP : END Defalut DEMO\n");


  printf("APP : start while demo\n");
  printf("APP : \n");
  strcpy(buf_out,"I'm Application\n");
  write(fd,buf_out,MAX_BUFFER);

  close(fd);
  return (0);
}
