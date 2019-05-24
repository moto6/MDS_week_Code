#include <stdio.h>

char *my_token(char *ps);                 // int형 변수의 주소를 반환하는 함수 선언

int main(void)
{


	return 0;
}

char *my_token(char *ps)
{
	const unsigned int MAX_LEN = 100;
	
	int j=0;//스페이스 위치 
	int srchpnt=0;
	int frontS=0,bheindS=0; 
	static i;
	static char *pfeedb;
	static char pword[MAX_LEN];
	if(pfeedb != ps) {
		i=0;
	}
	pfeedb = ps;
	//ps=='\0'
	
	for (j=0;j>=i;) {//스페이스 찾기 
		
		if( *(ps+srchpnt) ==' ') {
			j++;
			if() {
				frontS=
			}
		}
		srchpnt++;
	}
	
	
	return ;                        // 정적 지역 변수의 주소 반환
}
