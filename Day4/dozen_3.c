#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_intro(char (*intro[80]), char **pint);
int input_intro(char(*intro[80]));
void sort_intro(char **pint, int cnt);
void printf_intro(int mode, void *vp, int cnt);
int convert_string(const void *a, const void *b);

int main(void)
{
	char intro[10][80]; //10x80
	char *pint[10];
	int cnt;
	
	 
	
	init_intro(intro, pint);
	cnt = input_intro(intro);
	sort_intro(pint, cnt);
	printf_intro(1, pint, cnt);//0은 최초 입력된 인사말, 1은 정렬된 인사말 
	printf_intro(0, intro, cnt);

	return 0;
}
//키보드로 인사말 입력 후 사전순 정렬하여 출력
//이어서 입력한 순서대로 다시한번 출력
//정렬은 입력한 문자열을 바꾸지 않고 포인터 배열의 연결 순서를 변경
 

//init과 intro 연결 
void init_intro(char (*intro[80]), char **pint) {
	int i=0;
	for(i=0;i<10;i++) {
		pint[i] = intro+i;
		//*pint[i] = intro+i;
		//pint[i] = intro[i]; 
	}
}

int input_intro(char(*intro[80])) {
	int l_cnt;
	char buffer[80];
	while( 1 ) {//end가 입력되면 종료 //인사말 저장 
		printf("인사말 입력 : ");
		fgets(buffer,sizeof(buffer),stdin);	//이함수 쓰는법 , 입력받아 서 저장
		printf("입력받은 문자열 %s",buffer);
		if( 0 == strcmp("end",buffer )) {
			break;
		}
		else {
			strcpy(intro[l_cnt],buffer);
		}
		l_cnt++;
	}
	
	return l_cnt; 
}


//인사말 사전순 정렬
void sort_intro(char **pint, int cnt) {
	int i,j;
	for(i=0;i<9;i++ ) {
		for(j=0;j<9;j++) {
			if (strcpy(pint[i],pint[j]))
            {
            	/*
                temp        = data[j];
                data[j]     = data[j + 1];
                data[j + 1] = temp;
                */
            }
		}
	}
	  
}


 //0은 최초 입력된 인사말, 1은 정렬된 인사말
void printf_intro(int mode, void *vp, int cnt) {
	int i,j; 
	if(mode) {//정렬된 인사말 
		//정렬된 인사말 은 pint포인터 배열을 이용 
		//vp 로  pint 가 들어오는데, 이 순서로 정렬하기 
	} 
	else {//최초 입력된 인사말 vp를 이용한 intro2차원배열 문자열출력//2차원배열을 입력받는 배열포인터 
		for(i=0;i<10;i++) {
			puts(vp+i);
		}
		
	}
}

int convert_string(const void *a, const void *b) {
    
}


