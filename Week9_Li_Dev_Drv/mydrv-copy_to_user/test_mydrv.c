/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
//#include <string.h>
#define MAX_BUFFER 26
char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER];
void mySigHdlr(int signo);
char cpid;
int ret=0;
int main()
{
  int fd,i,mode,pid;
  pid = getpid();
  printf("pid is : %d\n",pid );
  fd = open("/dev/mydrv",O_RDWR);
  printf("fd = %d\r\n\n",fd);

  if(fd == -1) {
  	printf("you are fail to open div files, if you success ...\n");
  	printf("mknod /dev/mydrv c 240 0\n");
  	exit(1);
  }

  //sprintf(buf_out, "%d", pid);
  //cpid = itoa(pid);
  //strcpy(buf_out,"ohmygodd!");
  ret = write(fd,&pid,4);
  printf("return of write() : %d",ret);
  
  ret = read(fd,buf_in,20);
  printf("%s\n",buf_in);


  printf("%s\n","APP : I m going to sleep");
  if (signal(SIGINT, mySigHdlr) == SIG_ERR) {
    printf("\ncan't catch SIGINT\n");
  }
  while(1) {
  	sleep(200);
  }
  pause();

  close(fd);
  printf("%s\n","APP : wake up and the end");
  return (0);
}
void mySigHdlr(int signo)
{
  if (signo == SIGINT) {
    printf("received SIGINT\n");
  }
}
