#include <stdio.h>
#if 0
int main(void) 
{
	int a=10, b=20, res;
	
	res = (a>b) ? a:b;
	printf("큰값 : %d",a);
	
	return 0;	
}
//====================================================================
int main(void) 
{
	int a=10, b;
	
	res = (b = a>15) ? a+1:a-1;
	printf("큰값 : %d",a);
	
	return 0;	
}


//====================================================================
int main(void) 
{
	int i;
	while(1) {
		for(i=1;1<=5;i++)
		{
			if(i%3==0)continue;
			printf("CProg%d \n",i);
		}
		//printf("%d\n\n\n\r\n\r\n",i);
		if(i==5) break;
	}
	return 0;	
}

//====================================================================
int main(void)
{
	int i;
	for(i=0;i<=11;i++) {
		if(i%2)continue;
		printf("%d\n",i);
	}
}


//====================================================================
int main(void)
{
	int ary[] = {10,20,30,40,50};
	
	printf("배열명 자체의 값 : %u \n",ary);
	printf("첫 번째 배열요소의 주소 %u\n",&ary[0]);
	printf("배열명이 가리키는 요소의 값 %d \n",*ary);
	printf("첫 번째 배열 요소의 값 %d\n",ary[0]);
	
	return 0;
}

#endif
//====================================================================
int main(void)
{
	double ary[5] = {1.0, 2.1, 3.2, 4.3, 5.4 };
	int cnt=0,i=0;
	
	cnt = sizeof(ary)/sizeof(ary[0]);
	for(i=0 ; i<=cnt ; i++) {
		printf("%.1f \n",ary[5-i]);
	}
	return 0;
}
