/* test_mydrv.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include "ioctl_mydrv.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

#define MAX_BUFFER 26

void mySigHdlr(int signo);
int func1(void);
int func2(void);
int func3(void);
int func4(void);

char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER];
char cpid;
int ret=0;
int g_fd=0, g_pid=0;
char menudisp[] = "(1) : write\n\r(2) : read\n\r(3) : ioctl\n\r(4 or X) : exit\n\r";
int (*funcp[4])(void); //func pointer

int main()
{

	funcp[0]= NULL;
	funcp[1] = func1;
	funcp[2] = func2;
	funcp[3] = func3;
	funcp[4] = func4;
  int fd,i,mode,pid;
  int buf;
  pid = getpid();
  g_pid=pid;
  printf("pid is : %d\n",pid );
  fd = open("/dev/mydrv",O_RDWR);
  g_fd = fd;
  printf("fd = %d\r\n\n",fd);

  //file Open
  if(fd == -1) {
  	printf("you are fail to open div files, if you success ...\n");
  	printf("mknod /dev/mydrv c 240 0\n");
  	exit(0);
  }
  
  //signal registration
  if (signal(SIGINT, mySigHdlr) == SIG_ERR) {
    printf("\ncan't catch SIGINT\n");
  }
  printf("%s","APP : Welcome program\n");
  
  while(1) {
  	puts(menudisp);
  	puts("Always wait your Key Btn\n");
  	fflush(stdin);
  	scanf("%d",&buf);
  	printf("APP : %d is selected\n",buf);
  	getchar();
  	funcp[buf]();
  	sleep(1);
  }
  pause();

  close(fd);
  printf("%s\n","APP : wake up and the end\n");
  return (0);


}

void mySigHdlr(int signo) {
  if (signo == SIGINT) {
    printf("received SIGINT\n");
  }
}
  //ICTOL
  //sprintf(buf_out, "%d", pid);
  //cpid = itoa(pid);
  //strcpy(buf_out,"ohmygodd!");
 
  

  //
int func1(void) {
  ret = write(g_fd,&g_pid,4);
  printf("func1 : return of write() : %d\n",ret);
}

int func2(void) {
  ret = read(g_fd,buf_in,20);
  printf("func2 : buf_in of read();%s\n",buf_in);
}

int func3(void) {
  	printf("func3\n");
  	ioctl(g_fd,IOCTL_LED_1_ON,0);
  	sleep(1);
  	ioctl(g_fd,IOCTL_LED_2_ON,1);
}

int func4(void) {
  	printf("func4\n");
	exit(0);
}
