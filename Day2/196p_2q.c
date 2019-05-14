#include <stdio.h>
int primesv(unsigned int num);

int main(void)
{
	unsigned int buf=0;
	
	do {
		puts("2미만의 수 입력시 종료됩니다");
		
		printf("2이상의 정수를 입력하세요 : ");
		scanf("%d",&buf);
		
		if(buf>2){
			if(primesv(buf)) {
				puts("Prime number!");
			}
			else {
				puts("NO Prime");
					
			}
		}
	}while(buf>2);
	puts("program Terminated!");
	return 0;
}


int primesv(unsigned int num)
{
	if (num==1) {
		return num;//in case of prime!
	}
	else if(0==num%(num-1)) {
		return 0;
	}
	else {
		primesv(num-1);	
	}
}
