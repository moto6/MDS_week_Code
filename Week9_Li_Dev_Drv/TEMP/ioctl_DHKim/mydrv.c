
/***************************************
 * Filename: sk.c
 * Title: Skeleton Device
 * Desc: Implementation of system call
 ***************************************/
#include <linux/module.h>
#include <linux/init.h>
#include <linux/major.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>   /* kmalloc() */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <asm/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include "ioctl_mydrv.h"


#define GPGCON *(volatile unsigned long *)(kva)
#define GPGDAT *(volatile unsigned long *)(kva + 4)
MODULE_LICENSE("GPL");

static int sk_major = 0, sk_minor = 0;
static int result;
static dev_t sk_dev;
static void *kva;
#define DEVICE_NAME "sk"
module_param(sk_major, int, 0);


static struct cdev sk_cdev;

static int sk_register_cdev(void);
/* TODO: Define Prototype of functions */
static int sk_open(struct inode *inode, struct file *filp);
static int sk_release(struct inode *inode, struct file *filp);
static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int sk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
static int sk_ioctl ( struct file *filp, unsigned int cmd, unsigned long arg);
/* TODO: Implementation of functions */

static int sk_open(struct inode *inode, struct file *filp)
{
    printk("Device has been opened...\n");
    /* H/W Initalization */
    kva = ioremap(0x56000060, 16);
    printk("kva = 0x%x\n", (int)kva);
    GPGDAT |= 0xf << 4;
    GPGCON &= ~(0xff << 8);
    GPGCON |= 0x55 << 8;
    return 0;
}

static int sk_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");
    return 0;
}

static int sk_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
  volatile int i;
  printk("LED on\n");
  GPGDAT &= ~(0xf  <<  4);
  for(i=0; i<30; i++)
  {
    GPGDAT ^= (0xf << 4);
    mdelay(1000);
  }
  
  return count;
}

static int sk_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
  //char data[20] = "this is read func...";
  //copy_to_user(buf, data, count);
  return 0;
}


static int sk_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{  
  
  ioctl_buf *k_buf;
  int   i,err, size;  
  int leddata=0;    


  switch( cmd ) {  
      
    case IOCTL_LED_1_ON :
      printk("LED_1_ON\n");
      leddata = 0x01;
      GPGDAT=GPGDAT & ~(leddata<<4);
      mdelay(10);
      break;

    case IOCTL_LED_2_ON :
      for(i=0; i<30; i++)
      {
      GPGDAT ^= (0xf << 4);
      mdelay(1000);
      }
      /*
      printk("LED_2_ON\n");
      leddata = 0x10;
      GPGDAT=GPGDAT & ~(leddata<<4);
      mdelay(10);
      */
      break;
    /*
    case IOCTL_LED_1_OFF :
      printk("LED_1_OFF\n");
      break;
               
    case IOCTL_LED_2_OFF :
      printk("LED_2_OFF\n");
      break;
    
    case test :
      printk("IOCTL_TESTED Processed!!\n");
      break;
       */
    default :
      printk("Invalid IOCTL  Processed!!\n");
      break; 
  }  
  
    return 0;  
}  

struct file_operations sk_fops = { 
  //.owner   = THIS_MODULE,
  .open    = sk_open,
  .release = sk_release,
  .write   = sk_write,
  .read    = sk_read,
  .unlocked_ioctl   = sk_ioctl,
};



static int __init sk_init(void)
{
    printk("SK Module is up... \n");

  if((result = sk_register_cdev()) < 0)
  {
    return result;
  }

    return 0;
}

static void __exit sk_exit(void)
{
  printk("The module is down...\n");
  cdev_del(&sk_cdev);
  unregister_chrdev_region(sk_dev, 1);
}



static int sk_register_cdev(void)
{
  int error;

  /* allocation device number */
  if(sk_major) {
    sk_dev = MKDEV(sk_major, sk_minor);
    error = register_chrdev_region(sk_dev, 1, "sk");
  } else {
    error = alloc_chrdev_region(&sk_dev, sk_minor, 1, "sk");
    sk_major = MAJOR(sk_dev);
  }

  if(error < 0) {
    printk(KERN_WARNING "sk: can't get major %d\n", sk_major);
    return result;
  }
  printk("major number=%d\n", sk_major);

  /* register chrdev */
  cdev_init(&sk_cdev, &sk_fops);
  sk_cdev.owner = THIS_MODULE;
  sk_cdev.ops = &sk_fops;
  error = cdev_add(&sk_cdev, sk_dev, 1);

  if(error)
    printk(KERN_NOTICE "sk Register Error %d\n", error);

  return 0;
}



module_init(sk_init); 
module_exit(sk_exit); 


/*
  mydrv.c - kernel 3.0 skeleton device driver
               ioctl
 */

// #include <linux/module.h>
// #include <linux/moduleparam.h>
// #include <linux/init.h>

// #include <linux/kernel.h>   /* printk() */
// #include <linux/slab.h>   /* kmalloc() */
// #include <linux/fs.h>       /* everything... */
// #include <linux/errno.h>    /* error codes */
// #include <linux/types.h>    /* size_t */
// #include <asm/uaccess.h>
// #include <linux/kdev_t.h>
// #include <linux/cdev.h>
// #include <linux/device.h>
// #include "ioctl_mydrv.h"

// #define DEVICE_NAME "mydrv"
// static int mydrv_major = 240;
// module_param(mydrv_major, int, 0);


// static int mydrv_open(struct inode *inode, struct file *file)
// {
//   printk("mydrv opened !!\n");
//   return 0;
// }

// static int mydrv_release(struct inode *inode, struct file *file)
// {
//   printk("mydrv released !!\n");
//   return 0;
// }

// static ssize_t mydrv_read(struct file *filp, char __user *buf, size_t count,
//                 loff_t *f_pos)
// {
//   printk("mydrv_read is invoked\n");
//   return 0;

// }

// static ssize_t mydrv_write(struct file *filp,const char __user *buf, size_t count,
//                             loff_t *f_pos)
// {
//   printk("mydrv_write is invoked\n");
//   return 0;
// }

// static int mydrv_ioctl ( struct file *filp, unsigned int cmd, unsigned long arg)  
// {  
  
//    ioctl_buf *k_buf;
//    int   i,err, size;  
      
//    if( _IOC_TYPE( cmd ) != IOCTL_MAGIC ) return -EINVAL;  
//    if( _IOC_NR( cmd )   >= IOCTL_MAXNR ) return -EINVAL;  

//    size = _IOC_SIZE( cmd );   
 
//    if( size )  
//    {  
//        err = -EFAULT;  
//        if( _IOC_DIR( cmd ) & _IOC_READ  ) 
// 		err = !access_ok( VERIFY_WRITE, (void __user *) arg, size );  
//        else if( _IOC_DIR( cmd ) & _IOC_WRITE ) 
// 		err = !access_ok( VERIFY_READ , (void __user *) arg, size );  
//        if( err ) return err;          
//    }  
            
//    switch( cmd )  
//    {  
      
//        case IOCTL_MYDRV_TEST :
//             printk("IOCTL_MYDRV_TEST Processed!!\n");
// 	    break;

//        case IOCTL_MYDRV_READ :
//             k_buf = kmalloc(size,GFP_KERNEL);
//             for(i = 0 ;i < size;i++)
//                       k_buf->data[i] = 'A' + i;
//             if(copy_to_user ( (void __user *) arg, k_buf, (unsigned long ) size ))
// 	          return -EFAULT;   
//             kfree(k_buf);
//             printk("IOCTL_MYDRV_READ Processed!!\n");
// 	    break;
	    	       
//        case IOCTL_MYDRV_WRITE :
//             k_buf = kmalloc(size,GFP_KERNEL);
//             if(copy_from_user(k_buf,(void __user *) arg,size))
// 		   return -EFAULT;
//             printk("k_buf = %s\n",k_buf->data);
//             kfree(k_buf);
//             printk("IOCTL_MYDRV_WRITE Processed!!\n");
// 	    break;
	                          
//        case IOCTL_MYDRV_WRITE_READ : 
//             k_buf = kmalloc(size,GFP_KERNEL);
//             if(copy_from_user(k_buf,(void __user *) arg,size))
//                 return -EFAULT;
//             printk("k_buf = %s\n",k_buf->data);
            
//             for(i = 0 ;i < size;i++)
//                       k_buf->data[i] = 'Z' - i;
//             if(copy_to_user ( (void __user *) arg, k_buf, (unsigned long ) size ))
//        	   return -EFAULT;
// 	      kfree(k_buf);
//             printk("IOCTL_MYDRV_WRITE_READ Processed!!\n");
// 	    break;
       
//       default :
//             printk("Invalid IOCTL  Processed!!\n");
//             break; 
//     }  
  
//     return 0;  
// }  



// /* Set up the cdev structure for a device. */
// static void mydrv_setup_cdev(struct cdev *dev, int minor,
// 		struct file_operations *fops)
// {
// 	int err, devno = MKDEV(mydrv_major, minor);
    
// 	cdev_init(dev, fops);
// 	dev->owner = THIS_MODULE;
// 	dev->ops = fops;
// 	err = cdev_add (dev, devno, 1);
	
// 	if (err)
// 		printk (KERN_NOTICE "Error %d adding mydrv%d", err, minor);
// }


// static struct file_operations mydrv_fops = {
// 	.owner   = THIS_MODULE,
//    	.read	   = mydrv_read,
//     	.write   = mydrv_write,
// 	.unlocked_ioctl   = mydrv_ioctl,
// 	.open    = mydrv_open,
// 	.release = mydrv_release,
// };

// #define MAX_MYDRV_DEV 1

// static struct cdev MydrvDevs[MAX_MYDRV_DEV];

// static int mydrv_init(void)
// {
// 	int result;
// 	dev_t dev = MKDEV(mydrv_major, 0);

// 	/* Figure out our device number. */
// 	if (mydrv_major)
// 		result = register_chrdev_region(dev, 1, DEVICE_NAME);
// 	else {
// 		result = alloc_chrdev_region(&dev,0, 1, DEVICE_NAME);
// 		mydrv_major = MAJOR(dev);
// 	}
// 	if (result < 0) {
// 		printk(KERN_WARNING "mydrv: unable to get major %d\n", mydrv_major);
// 		return result;
// 	}
// 	if (mydrv_major == 0)
// 		mydrv_major = result;

// 	mydrv_setup_cdev(MydrvDevs,0, &mydrv_fops);
// 	printk("mydrv_init done\n");	
// 	return 0;
// }

// static void mydrv_exit(void)
// {
// 	cdev_del(MydrvDevs);
// 	unregister_chrdev_region(MKDEV(mydrv_major, 0), 1);
// 	printk("mydrv_exit done\n");
// }

// module_init(mydrv_init);
// module_exit(mydrv_exit);

// MODULE_LICENSE("Dual BSD/GPL");
// */
