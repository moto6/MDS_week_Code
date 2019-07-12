/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_BUFFER 26
char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER]="Shutdown timer";

int main()
{
  int fd,i,mode;
  
  //system("insmod ##.ko");
  //system("mknod /dev/led/c 240 0");
  fd = open("/dev/myled",O_RDWR);
  printf("fd = %d\n",fd);

  if(fd == -1) {
  	printf("you are fail to open div files, if you success ...\n");
  	printf("mknod /dev/myled c 240 0\n");
  	exit(1);
  }

  //for(i=0;i<10;i++) {
    write(fd,buf_out,MAX_BUFFER);
    printf("APP : write()-> timer off\n");
    sleep(1);
  //}


  printf("APP : close() : %d\n",   close(fd));
  return (0);
}
