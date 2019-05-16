#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void init_intro(char (*intro)[80], char **pint);
int input_intro(char (*intro)[80]);
void sort_intro(char **pint, int cnt);
void printf_intro(int mode, void *vp, int cnt);


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


//init과 intro 연결 
void init_intro(char (*intro)[80], char **pint) {
	int i=0;
	for(i=0;i<10;i++) {
		pint[i] = intro[i];
	}
}

int input_intro ( char (*intro)[80] ) {

	int l_cnt;
	char buffer[80];
	while( 1 ) {//end가 입력되면 종료 //인사말 저장 
		/*
		printf("인사말 입력 : ");
		
		  fgets( buffer, 79, stdin); //띄어쓰기 문장 입력하면 셧다운 
		//gets( intro[i]);	//이함수 쓰는법 , 입력받아 서 저장
		//strcpy( buffer, intro[i] );
		printf("입력받은 문자열: %s",buffer);
		strcpy(intro[l_cnt],buffer);
		
		printf("입력받은 문자열: %s",intro+l_cnt);
		if( 0 == strcmp("end\n",buffer  )) {
			break;
		}
		else {}
		l_cnt++;
		
		*/
		printf("> 인사말 입력 : ");
		gets(buffer);
		if(strcmp(buffer, "end") == 0) break;
		strcpy(intro[l_cnt], buffer);
		l_cnt++;
	}
	fflush(stdin);
	return l_cnt; 
}


//인사말 사전순 정렬
void sort_intro(char **pint, int cnt) {
	int i,j;
	for(i=0;i<9;i++ ) {
		for(j=0;j<9;j++) {
			if (strcmp(pint[i],pint[j]) < 0 )
            {
            	
            	char* tmp = pint[i];
            	pint[i] = pint[j];
            	pint[j] = tmp;
            }
		}
	}
	  
	puts("end of sort");
}



 //0은 최초 입력된 인사말, 1은 정렬된 인사말
void printf_intro(int mode, void *vp, int cnt) {
	int i; 
	char **intp;
	char (*intro)[80];
	
	if ( mode == 0 ) {
    	char (*intro)[80] = vp;

    	puts("원래대로 출력 .... ");
        //printf("original list is :\n");
        for (i = 0; i < cnt; i++) {
        	printf("%s", intro[i]);	
		}
    }
	
	
	else if( mode == 1)  {//정렬된 인사말 
		char **intp = vp;
		puts("사전순으로 출력 ... \n");		//정렬된 인사말 은 pint포인터 배열을 이용 
		for( i=0; i<cnt;i++) {	//vp 로  pint 가 들어오는데, 이 순서로 정렬하기 
			printf("%s\n", intp[i]);
		} 
	}
	
	
	else {//최초 입력된 인사말 vp를 이용한 intro2차원배열 문자열출력//2차원배열을 입력받는 배열포인터 
		for(i=0;i<10;i++) {
			puts("un intended ERROR!!!!!!!");
		}
		
	}
}

//
/*
/

//

void printf_intro(int mode, void *vp, int cnt)
{
	int i;

	if(mode == 0)
	{
		char (*intro)[80] = vp;
		printf("\n@ 입력순으로 출력...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intro[i]);
		}
			fflush(stdin);
	}
	else if(mode == 1)
	{
		char **intp = vp;
		printf("\n@ 사전순으로 출력...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intp[i]);
		}
	}
}

//
*/

