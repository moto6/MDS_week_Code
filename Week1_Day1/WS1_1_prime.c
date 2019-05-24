//primenumber
#include <stdio.h>
int main(void) {
	int val=0, i=0;
	int pridca=0; 
	do {
		
		printf("숫자를 입력하세요 <종료 : 0> :");
		scanf( "%d" ,&val);
		//out of range exception will be add 
		if (val == 0) {
			puts("bye~");
			return 0;
		}
		if (val == 1) {
			printf("소수가 아닙니다, 1입력\n");
		}
		 
		
		i=val-1;
		
		while( i >= 2 ) {
			if(0 == (val%i)) {
				printf("소수가 아닙니다\n");
				break;
			}
			else {
				i--;
			}
		}
		
		if(i==1) {
			printf("소수 입니다\n");
		}
		 
		
	}while(1);

return 0;
}
