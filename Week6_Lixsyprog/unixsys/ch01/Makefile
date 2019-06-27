# Makefile

CC=gcc
CFLAGS=
OBJS=ex1_3_main.o ex1_3_addnum.o
LIBS=
all:    add

add:    $(OBJS)
	$(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)

ex1_3_main.o:         ex1_3_main.c
	$(CC) $(CFLAGS) -c ex1_3_main.c
ex1_3_addnum.o:       ex1_3_addnum.c
	$(CC) $(CFLAGS) -c ex1_3_addnum.c

clean:
	rm -f $(OBJS) add core
