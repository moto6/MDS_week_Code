#include "myh.h"

int main(void)
{
	struct stat buf;
	stat("unix.txt",&buf);

	printf("Mode = %o,(hxea:%x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
	
	if(S_ISFIFO(buf.st_mode)) printf("unix.txt : FIFO\n");
	if(S_ISDIR(buf.st_mode)) printf("unix.txt : \n");
	if(S_ISREG(buf.st_mode)) printf("unix.txt : \n");
return 0;	
}
