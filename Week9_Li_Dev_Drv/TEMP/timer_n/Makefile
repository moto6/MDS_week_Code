obj-m	:= timerTest_mod.o

#KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22
PWD	:= $(shell pwd)
APP  = APP_DHKim

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	cp timerTest_mod.ko /nfs/rootfs/workSpace
	cp APP_DHKim /nfs/rootfs/workSpace/
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
