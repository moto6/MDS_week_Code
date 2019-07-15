#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO	*/
#include <linux/init.h>		/* Needed for the macros */
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/fs.h>       /* everything... */
#include <linux/types.h>    /* size_t */

#include <asm/io.h>
#include <asm/irq.h>
#include <asm/uaccess.h>

#include <mach/gpio.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>


#define	DRIVER_AUTHOR	"DHKim of southkorea"
#define	DRIVER_DESC		"DHKim sample DD"
#define DRV_NAME        "mydrv"
#define DEVICE_NAME 	"mydrv"
#define MAX_MYDRV_DEV 1

static int mydrv_major = 240;
module_param(mydrv_major, int, 0);


//from NCH.. jubjub!
static char DDin_buf[50];
static char DDout_buf[50];

//
static void mydrv_setup_cdev(struct cdev *dev, int minor,struct file_operations *fops);

//
static int mydrv_open(struct inode *inode, struct file *file)
{
  printk("DHKim DD.drv opened !!\n");
  return 0;
}

static int mydrv_release(struct inode *inode, struct file *file)
{
  printk("DHKim D.drv released !!\n");
  return 0;
}


static ssize_t mydrv_read(struct file *filp, char __user *buf, size_t count,
                loff_t *f_pos)
{
  char *k_buf;
  int i;
    printk("read in func\n");

  k_buf = kmalloc(count,GFP_KERNEL);
  for(i = 0 ;i < count;i++)
      k_buf[i] = 'A' + i;
  
  if(copy_to_user(buf,k_buf,count)) {
  	return -EFAULT;
  }
  printk("read is invoked in kerneland HEAP\n");
  
  if(copy_to_user(buf, DDout_buf, count)) {
	return -EFAULT;
  }
  printk("success cpy2u() ->> DDout_buf");

  kfree(k_buf);
  return 0;

}

static ssize_t mydrv_write(struct file *filp,const char __user *buf, size_t count,
                            loff_t *f_pos)
{
	char data[11];
	get_user(id,(int *)buf);
	printk("\n [ KDD ] id = %d",id);
	my_kill_proc(id,SIGUSR1);
	return count;

  /*	
  char *k_buf;
  printk("write in func\n");

  k_buf = kmalloc(count,GFP_KERNEL);
  if(copy_from_user(k_buf,buf,count)) {
  	return -EFAULT;
  }
  printk("k_buf = %s\n",k_buf);
  printk("write is invoked\n");
  
  if(copy_from_user(DDin_buf, buf, count)) {
	return -EFAULT;
  }
  printk("copy_from_user() func success ->>DDin_buf");
  kfree(k_buf);
  return 0;
  */
}


static irqreturn_t keyinterrupt_func1(int irq, void *dev_id, struct pt_regs *resgs)
{
      printk("Key 0 pressed!!!(%d)\n",irq);
      printk("KDD : %s",DDin_buf);
      return IRQ_HANDLED;
}

static irqreturn_t keyinterrupt_func2(int irq, void *dev_id, struct pt_regs *resgs)
{
      printk("Key 1 pressed!!!(%d)\n",irq);
      return IRQ_HANDLED;
}

static irqreturn_t keyinterrupt_func_mls(int irq, void *dev_id, struct pt_regs *resgs)
{		//GPG2,3,4,5,6 =>> 5 keys
      //printk("Key (%d) pressed!!!\n",irq);
      switch(irq)
      {
      	case 18 ://in case of SW4,9
      		printk("in case of SW4,9\n");
      		break;
      	case 19 ://in case of SW5,10
      		printk("in case of SW5,10\n");
      		break;
      	case 48 ://in case of SW6,11
      		printk("in case of SW6,11\n");
      		break;
      	case 49 ://in case of SW7,12
      		printk("in case of SW7,12\n");
      		break;
      	case 50 ://in case of SW8,13
      		printk("in case of SW8,13\n");
      		break;
      }


      return IRQ_HANDLED;
}
/*
//how to solv this 10 keys problem
1.GPF7,GPG0 set 0(Low) -> every 10 key recognize btn
2.if btn is pushh ->> through in case of inerrput
3.for ex case 18, ->> 
4.1. up 5 keys
  rGPFDAT &= ~(0x1<<7);   //Clear GPF7
  rGPGDAT |= (0x1);       //Set GPG0
4.2 down 5 key
  rGPFDAT |= (0x1<<7);    //Set GPF7
  rGPGDAT &= ~(0x1);      //Clear GPG0
5. each row(colum?), set port GPIO, NOT EXINT
6. Read GPIO (decision Making) up or down
7. save exect key 
8. recover every key interrupt mode
9. return exect key (swq about no.7)
*/
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


/***********************************************
************************************************
************************************************
***********************************************/
static struct file_operations mydrv_fops = {
	.owner   = THIS_MODULE,
   	.open    = mydrv_open,
	.read	 = mydrv_read,
    .write   = mydrv_write,
	.release = mydrv_release,
};


static struct cdev MydrvDevs[MAX_MYDRV_DEV];

static int __init init(void)
{
	int result;
	int ret;
	dev_t dev = MKDEV(mydrv_major, 0);
	//=section of inerterupt=======================================================================
	printk(KERN_INFO "Hello DD world !!\n");
       	///*
    	// set Interrupt mode
        s3c_gpio_cfgpin(S3C2410_GPF(0), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(1), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(2), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(3), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(4), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(5), S3C_GPIO_SFN(2));
        s3c_gpio_cfgpin(S3C2410_GPF(6), S3C_GPIO_SFN(2));

        if(request_irq(IRQ_EINT0,(void *)keyinterrupt_func1,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL))
        {
                printk("IRQ_EINT0 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        if(request_irq(IRQ_EINT1, (void *)keyinterrupt_func2,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL)) 
        {
                printk("IRQ_EINT1 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        if(request_irq(IRQ_EINT2, (void *)keyinterrupt_func_mls,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL)) 
        {
                printk("IRQ_EINT2 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        if(request_irq(IRQ_EINT3, (void *)keyinterrupt_func_mls,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL)) 
        {
                printk("IRQ_EINT3 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        if(request_irq(IRQ_EINT4, (void *)keyinterrupt_func_mls,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL)) 
        {
                printk("IRQ_EINT4 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        if(request_irq(IRQ_EINT5, (void *)keyinterrupt_func_mls,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL)) 
        {
                printk("IRQ_EINT5 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        if(request_irq(IRQ_EINT6, (void *)keyinterrupt_func_mls,IRQF_DISABLED|IRQF_TRIGGER_FALLING, DRV_NAME, NULL)) 
        {
                printk("IRQ_EINT6 failed to request external interrupt.\n");
                ret = -ENOENT;
                return ret;
        }

        printk(KERN_INFO "%s successfully intq loaded\n", DRV_NAME);
        //*/
	//=section of inerterupt=======================================================================
	printk("This Module major number : 240\n");
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
	printk("Hello.ko module init done\n");	

	return 0;
}

static void __exit cleanup(void)
{
	cdev_del(MydrvDevs);
	unregister_chrdev_region(MKDEV(mydrv_major, 0), 1);
	printk("hello.ko DD module exit done\n");
	//=====================================================
	///*
	printk(KERN_INFO "Goodbye, world 4.\n");
    free_irq(IRQ_EINT0, NULL);
    free_irq(IRQ_EINT1, NULL);
    free_irq(IRQ_EINT2, NULL);
    //free_irq(IRQ_EINT3, NULL);
    //free_irq(IRQ_EINT4, NULL);
    //free_irq(IRQ_EINT5, NULL);
    printk(KERN_INFO "%s successfully removed\n", DRV_NAME);
	//*/
}

module_init(init);
module_exit(cleanup);
/* Get rid of taint message by declaring code as GPL. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);		/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
MODULE_SUPPORTED_DEVICE("testdevice");
