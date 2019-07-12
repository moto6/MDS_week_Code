#include <stdio.h>


int main(void)
{
	int arr[5][6]={0};
	
	int i,j;

	int sum;
	 
	//초기화 : 기본값 넣기 
	for(i=0;i<4;i++) {
		for(j=0;j<5;j++) {
			arr[i][j]=(i*5)+j+1;
		}
		
	}

	//행의 합 넣기 
	for(i=0;i<4;i++) {
		for(j=0;j<5;j++) {
			arr[i][5] +=arr[i][j];
		}	
		
	}
	
	//열의 합 넣기 
	for(i=0;i<6;i++) {
		for(j=0;j<4;j++) {
			arr[4][i] +=arr[j][i];
		}	
		
	}
	//*/
	//출력 
	for(i=0;i<5;i++) {
		for(j=0;j<6;j++) {
			printf("%d\t",arr[i][j]);		
		}
		puts("");
	}
	

	return 0;
}


