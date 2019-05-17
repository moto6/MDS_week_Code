#include <stdio.h>

//=======================================
/*
int main(void)
{
	int (*fp)(int, int);
	int res;
	
	fp = sum;
	res=fp(10,20);
	printf("operation : 10+20 = %d"res);

	fp = sub;
	res=fp(10,20);
	printf("operation : 10-20 = %d"res);

	fp=mul;
	res=fp(10,20);
	printf("operation : 10+20 = %d"res);

	fp=irq;
	res=fp(10,20);
	printf("operation : 10+20 = %d"res);

	fp=rmd;
	res=fp(10,20);
	printf("operation : 10+20 = %d"res);

	return 0;
}

int sum(int a,int b);
{
	return ( a + b );
}
int sub(int a,int b);
{
	return ( a - b );
}
int mul(int a,int b);
{
	return ( a*b );
}
int irq(int a,int b);
{
	return ( a/b );
}
int rmd(int a,int b);
{
	return ( a%b );
}


//=======================================
*/

int main (void) {
	int a = 10;
	double b = 3.5;
	void *vp;
	
	vp = &a;
	printf("a : %d\n", *(int *)vp);
	
	vp = &b;
	printf("b : %d\n", *(double *)vp);
}
