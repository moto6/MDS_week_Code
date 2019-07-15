/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#include "ioctl_mydrv.h"

int main()
{
  int fd,i,size,ret;
  ioctl_buf *buf_in,*buf_out;
  
  size = sizeof(ioctl_buf);
  buf_in = (ioctl_buf *)malloc(size);
  buf_out = (ioctl_buf *)malloc(size);
  
  fd = open("/dev/SK",O_RDWR);
  printf("OPEN fd = %d\n", fd);

  ioctl(fd,IOCTL_LED_1_ON,0);
  sleep(1);
  ioctl(fd,IOCTL_LED_2_ON,1);
  
  //sleep(500);
  //Sleep(60000);
  /*
  //ioctl(fd, IOCTL_MYDRV_READ, buf_in );
  printf("buf_in = %s\n",buf_in->data);
  
  for(i = 0;i < size;i++)
     buf_out->data[i] = 'a' + i;
  ioctl(fd, IOCTL_MYDRV_WRITE, buf_out );
  
  for(i = 0;i < size;i++)
     buf_out->data[i] = 'z' - i;
  ioctl(fd, IOCTL_MYDRV_WRITE_READ, buf_out );
  
  printf("buf_in = %s\n",buf_out->data);
  */

  free(buf_in);
  free(buf_out);
  close(fd);
  printf("stopped\n");
  return (0);
}
