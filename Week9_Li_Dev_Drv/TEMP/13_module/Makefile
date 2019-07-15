obj-m += hello.o
obj-m += hello_param.o

#KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22

APP  = APP_DHKim

all:
	make -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	cp APP_DHKim /nfs/rootfs/workSpace/
	cp hello.ko /nfs/rootfs/workSpace/

clean:
	make -C $(KDIR) SUBDIRS=$(PWD) clean

