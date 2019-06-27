#include "myh.h"

int main(void) {
	struct stat buf;
	stat("unix.txt", &buf);

	printf("Mode = %o (Hexadeciaml:%x) \n",(unsigned int)buf.st_mode, (unsigned int)buf.st_mode);



	if((buf.st_mode & S_IREAD) != 0)
		printf("user has a read permission\n");

	if((buf.st_mode & (S_IREAD >> 3)) !=0 )
		printf("group has a read permisson\n");

	if((buf.st_mode & S_IROTH) != 0)
		printf("other have///\n");

return 0;
}
