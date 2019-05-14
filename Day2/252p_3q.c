#include <stdio.h>
int main(void) 
{
	
	int rnum[6]={0,0,0,0,0,0};
	int i=0,j=0;
	int buff= 0;
	int jb = 0;
	//디버깅
	printf("입력된 로또번호 : ");
	for(i=0;i<6;i++) {
		printf("\t%d",rnum[i]);
	}
	puts(""); 
	//
	for(i=1;i<7;i++) {
		printf("로또 번호 입력 : ");
		scanf("%d", &buff);
	 	printf("buff = %d\n",buff);
		jb=1;
		
		for(j=0;j<i;j++) {
			if( buff == rnum[i] ) {
				jb=0;
				break;
			}
		}
		
		if(jb) {
			rnum[i-1]= buff;
		}
		else {
			printf("같은 번호가 있습니다!");
			i=i-1;
		}
		 
	}
	
	
	printf("입력된 로또번호 : ");
	for(i=0;i<6;i++) {
		printf("\t%d",rnum[i]);
	}
	
}
