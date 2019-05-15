#include <stdio.h>
void rotate(int *pa, int *pb, int *pc);

int main (void) 
{
	int a=1,b=2,c=3;
	char buf=0;
	printf("init value : a=%d, b=%d, c=%d",a,b,c)	;
	do{
		scanf("%c",&buf);
		
		if(buf != 10) {
			break;
		}
		else {
			rotate(&a,&b,&c);
			printf("a=%d , b=%d , c=%d",a,b,c);
		}
		
	} while(1);

	return 0;
}


void rotate(int *pa, int *pb, int *pc)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
	
	return;
}
