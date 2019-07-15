#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>   /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <asm/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>
#include <linux/gpio.h>
#include <linux/sched.h>
#include "ioctl_mydrv.h"

MODULE_LICENSE("Dual BSD/GPL");

#define GPGCON *(volatile unsigned long *)(kva)
#define GPGDAT *(volatile unsigned long *)(kva + 4)
#define DEVICE_NAME "mydrv"

static int mydrv_major = 241, mydrv_minor = 0;;
module_param(mydrv_major, int, 0);
//module_param(sk_major, int, 0);
static int my_kill_proc(pid_t pid, int sig);
static int result;
static void *kva;
static dev_t mydrv_dev;
static struct cdev mydrv_cdev;

//mydrv_setup_cdev
static void mydrv_setup_cdev(struct cdev *dev, int minor,
    struct file_operations *fops);
//
static int mydrv_register_cdev(void);
static int mydrv_open(struct inode *inode, struct file *filp);
static int mydrv_release(struct inode *inode, struct file *filp);
static int mydrv_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static int mydrv_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
static int mydrv_ioctl ( struct file *filp, unsigned int cmd, unsigned long arg);
//


static int mydrv_open(struct inode *inode, struct file *file)
{
  printk("mydrv opened !!\n");
  kva = ioremap(0x56000060, 16);
  printk("kva = 0x%x\n", (int)kva);
  GPGDAT |= 0xf << 4;
  GPGCON &= ~(0xff << 8);
  GPGCON |= 0x55 << 8;
  return 0;
}

static int mydrv_release(struct inode *inode, struct file *file)
{
  printk("mydrv released !!\n");
  return 0;
}

static ssize_t mydrv_read(struct file *filp, char __user *buf, size_t count,
                loff_t *f_pos)
{
  //volatile int i;
  
  printk("KDD : Hello i'm kernel mydrv_read()\n");
  
  //LED Toggle func in READ method
  GPGDAT ^= (0xf << 4);

  return 0;

}

static ssize_t mydrv_write(struct file *filp,const char __user *buf, size_t count,
                            loff_t *f_pos)
{	
  int id;
	//char data[11];
	get_user(id,(int *)buf);
	printk("\n [ KDD ] id = %d\n",id);\
	//mdelay(1000);
	//mdelay(1000);
	my_kill_proc(id,SIGUSR1);
	return count;
/*
  char *k_buf;
    
  k_buf = kmalloc(count,GFP_KERNEL);
  if(copy_from_user(k_buf,buf,count))
  	return -EFAULT;
  printk("k_buf = %s\n",k_buf);
  printk("mydrv_write is invoked\n");
  kfree(k_buf);
  return 0;*/
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



static struct file_operations mydrv_fops = {
	.owner           = THIS_MODULE,
  .read	           = mydrv_read,
  .write           = mydrv_write,
	.open            = mydrv_open,
  .unlocked_ioctl  = sk_ioctl,
	.release         = mydrv_release,
};

#define MAX_MYDRV_DEV 1

static struct cdev MydrvDevs[MAX_MYDRV_DEV];

static int mydrv_init(void)
{
	int result;
	dev_t dev = MKDEV(mydrv_major, 0);

	/* Figure out our device number. */
	if (mydrv_major)
		result = register_chrdev_region(dev, 1, DEVICE_NAME);
	else {
		result = alloc_chrdev_region(&dev,0, 1, DEVICE_NAME);
		mydrv_major = MAJOR(dev);
	}
	if (result < 0) {
		printk(KERN_WARNING "mydrv: unable to get major %d\n", mydrv_major);
		return result;
	}
	if (mydrv_major == 0)
		mydrv_major = result;

	mydrv_setup_cdev(MydrvDevs,0, &mydrv_fops);


  if((result = mydrv_register_cdev()) < 0)
  {
    return result;
  }

	printk("mydrv_init done\n");	
	return 0;
}

static void mydrv_exit(void)
{
	cdev_del(MydrvDevs);
	unregister_chrdev_region(MKDEV(mydrv_major, 0), 1);
	printk("mydrv_exit done\n");
}



static int my_kill_proc(pid_t pid, int sig) {
    int error = -ESRCH;           /* default return value */
    struct task_struct* p;
    struct task_struct* t = NULL; 
    struct pid* pspid;
    rcu_read_lock();
    p = &init_task;               /* start at init */
    do {
        if (p->pid == pid) {      /* does the pid (not tgid) match? */
            t = p;    
            break;
        }
        p = next_task(p);         /* "this isn't the task you're looking for" */
    } while (p != &init_task);    /* stop when we get back to init */
    if (t != NULL) {
        pspid = t->pids[PIDTYPE_PID].pid;
        if (pspid != NULL) error = kill_pid(pspid,sig,1);
    }
    rcu_read_unlock();
    return error;
}

/* Set up the cdev structure for a device. */
static void mydrv_setup_cdev(struct cdev *dev, int minor,
    struct file_operations *fops)
{
  int err, devno = MKDEV(mydrv_major, minor);
    
  cdev_init(dev, fops);
  dev->owner = THIS_MODULE;
  dev->ops = fops;
  err = cdev_add (dev, devno, 1);
  
  if (err)
    printk (KERN_NOTICE "Error %d adding mydrv%d", err, minor);
}

static int mydrv_register_cdev(void)
{
  int error;

  /* allocation device number */
  if(mydrv_major) {
    mydrv_dev = MKDEV(mydrv_major, mydrv_minor);
    printk(KERN_INFO "timerTest Module is Loaded!! ....\n");
    error = register_chrdev_region(mydrv_dev, 1, "mydrv");
  } else {
    error = alloc_chrdev_region(&mydrv_dev, mydrv_minor, 1, "mydrv");
    mydrv_major = MAJOR(mydrv_dev);
  }

  if(error < 0) {
    printk(KERN_WARNING "mydrv: can't get major %d\n", mydrv_major);
    return result;
  }
  printk("mydrv major number=%d\n", mydrv_major);

  /* register chrdev */
  cdev_init(&mydrv_cdev, &mydrv_fops);
  mydrv_cdev.owner = THIS_MODULE;
  mydrv_cdev.ops = &mydrv_fops;
  error = cdev_add(&mydrv_cdev, mydrv_dev, 1);

  if(error)
    printk(KERN_NOTICE "mydrv Register Error %d\n", error);

  return 0;
}

module_init(mydrv_init);
module_exit(mydrv_exit);
