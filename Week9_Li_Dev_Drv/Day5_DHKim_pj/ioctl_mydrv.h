#ifndef _IOCTL_MYDRV_H_
#define _IOCTL_MYDRV_H_

//#define IOCTL_MAGIC    254
#define LED_ON_MAGIC     254
typedef struct
{
	unsigned char data[26];	
	
} __attribute__ ((packed)) ioctl_buf;

/*
#define IOCTL_MYDRV_TEST                _IO(  IOCTL_MAGIC, 0 )
#define IOCTL_MYDRV_READ                _IOR( IOCTL_MAGIC, 1 , ioctl_buf )
#define IOCTL_MYDRV_WRITE               _IOW( IOCTL_MAGIC, 2 , ioctl_buf )
#define IOCTL_MYDRV_WRITE_READ     _IOWR( IOCTL_MAGIC, 3 , ioctl_buf )
*/

#define IOCTL_LED_1_ON     _IO( LED_ON_MAGIC, 0)
#define IOCTL_LED_2_ON     _IO( LED_ON_MAGIC, 1)
#define IOCTL_LED_3_ON     _IO( LED_ON_MAGIC, 2)
#define IOCTL_LED_4_ON     _IO( LED_ON_MAGIC, 3)

#define IOCTL_LED_1_OFF     _IO( IOCTL_MAGIC, 4)
#define IOCTL_LED_2_OFF     _IO( IOCTL_MAGIC, 5)
#define IOCTL_LED_3_OFF     _IO( IOCTL_MAGIC, 6)
#define IOCTL_LED_4_OFF     _IO( IOCTL_MAGIC, 7)




#define IOCTL_MAXNR                   4
  
#endif // _IOCTL_MYDRV_H_

