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
#define DEVICE_NAME "LED"
#define GPGCON *(volatile unsigned long *)(kva)
#define GPGDAT *(volatile unsigned long *)(kva + 4)

struct timer_list timer;

static int LED_major = 0, LED_minor = 0;
static int result;
static dev_t LED_dev;
static void *kva;


#define	DRIVER_AUTHOR	"DHKim of southkorea"
#define	DRIVER_DESC		"DHKim sample DD"
#define DRV_NAME        "mydrv"
#define DEVICE_NAME 	"mydrv"
#define MAX_MYDRV_DEV 1

module_param(LED_major, int, 0);

//rmmod timerTest_mod.ko
static struct cdev LED_cdev;
static int LED_register_cdev(void);

static int LED_open(struct inode *inode, struct file *filp);
static int LED_release(struct inode *inode, struct file *filp);
static int LED_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int LED_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
/* TODO: Implementation of functions */

static int LED_open(struct inode *inode, struct file *filp)
{

    printk("Device has been opened...\n");
    /* H/W Initalization */
    //kva = ioremap(0x56000060, 16);
    //printk("kva = 0x%x\n", (int)kva);
    GPGDAT |= 0xf << 4;
    GPGCON &= ~(0xff << 8);
    GPGCON |= 0x55 << 8;
    return 0;
}

static ssize_t LED_release(struct inode *inode, struct file *filp)
{
    printk("Device has been closed...\n");
    return 0;
}
//
static ssize_t LED_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	static volatile char ststr[] = "Shutdown timer";
	static volatile char * k_buf;
  	//static volatile int i;
  	printk("LED on\n");
  	GPGDAT ^= (0xf << 4);

    
  	k_buf = kmalloc(count,GFP_KERNEL);
  	if(copy_from_user(k_buf,buf,count)) {
  		return -EFAULT;
  	}
  	printk("KDD : k_buf = %s\n",k_buf);
  	if(strcmp(k_buf,ststr)) {
		del_timer(&timer);
  		printk("Shutdown timer fucn activated\n");
  	}
  	kfree(k_buf);
  	return count;
}

static int LED_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
  printk("KDD : LED_read() called");
  return 0;
}


/*
// file ops
  .open    = LED_open,
  .release = LED_release,
  .write   = LED_write,
  .read    = LED_read,
*/
void my_timer(unsigned long data)
{
	//int i;
	//for(i=1; i<=data; i++) {
	//	printk("Kernel Timer Time-Out Function Doing_%d...\n", i);
	//}
	//volatile int i;
	//printk("LED on\n");
	GPGDAT ^= (0xf << 4);
	//GPGDAT &= ~(0xf  <<  4);
  	// for(i=0; i<30; i++)
  	// {
   // 		GPGDAT ^= (0xf << 4);
   //  	mdelay(1000);
  	// }
  
	timer.expires = jiffies + 1*HZ;
	add_timer(&timer);

	//printk("Kernel Timer Time-Out Function Done!!!\n");
}


struct file_operations LED_fops = { 
  .owner   = THIS_MODULE,
  .open    = LED_open,
  .release = LED_release,
  .write   = LED_write,
  .read    = LED_read,
  //.unlocked_ioctl   = LED_ioctl,
};


/*
static int LED_major = 0, LED_minor = 0;
static int result;
static dev_t LED_dev;
*/

static int __init timerTest_init(void)
{
	LED_dev = MKDEV(LED_major, 0);
	printk(KERN_INFO "timerTest Module is Loaded!! ....\n");

	init_timer(&timer);
	//from origin code
	//timer.expires = get_jiffies_64() + 3*HZ;
	timer.expires = jiffies + 3*HZ;
	timer.function = my_timer;
	timer.data = 5;
	add_timer(&timer);

    printk("LED Module By LED Module is up... \n");
    
    	/* Figure out our device number. */
	if (LED_major) {
		result = register_chrdev_region(LED_dev, 1, DEVICE_NAME);
	}
	else {
		result = alloc_chrdev_region(&LED_dev,0, 1, DEVICE_NAME);
		LED_major = MAJOR(LED_dev);
	}
	if (result < 0) {
		printk(KERN_WARNING "LED_dev: unable to get major %d\n", LED_major);
		return result;
	}
	if (LED_major == 0) {
		LED_major = result;
	}
    if((result = LED_register_cdev()) < 0) {
      return result;
    }
    
    kva = ioremap(0x56000060, 16);
    printk("kva = 0x%x\n", (int)kva);
    GPGDAT |= 0xf << 4;
    GPGCON &= ~(0xff << 8);
    GPGCON |= 0x55 << 8;

	//mydrv_setup_cdev(MydrvDevs,0, &mydrv_fops);
	printk("timerTest_init done\n");	
	return 0;
}


static int LED_register_cdev(void)
{
  int error;

  /* allocation device number */
  if(LED_major) {
    LED_dev = MKDEV(LED_major,LED_minor);
    error = register_chrdev_region(LED_dev, 1, "LED");
  } else {
    error = alloc_chrdev_region(&LED_dev,LED_minor, 1, "LED");
    LED_major = MAJOR(LED_dev);
  }

  if(error < 0) {
    printk(KERN_WARNING "LED: can't get major %d\n", LED_major);
    return result;
  }
  printk("major number=%d\n", LED_major);

  /* register chrdev */
  cdev_init(&LED_cdev, &LED_fops);
  LED_cdev.owner = THIS_MODULE;
  LED_cdev.ops = &LED_fops;
  error = cdev_add(&LED_cdev, LED_dev, 1);

  if(error)
    printk(KERN_NOTICE "LED Register Error %d\n", error);

  return 0;
}


static void __exit timerTest_exit(void)
{
	printk("timerTest Module is Unloaded ....\n");
	del_timer(&timer);
	
	printk("The module is down...\n");
	cdev_del(&LED_cdev);
	unregister_chrdev_region(LED_dev, 1);
}

module_init(timerTest_init);
module_exit(timerTest_exit);

MODULE_LICENSE("Dual BSD/GPL");


/*
 #tail -f /var/log/messages
*/
