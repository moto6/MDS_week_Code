#include <stdio.h>

void cal (int srt,int len);
int monthlen(int month);
int yun_year(int yyy);
int yun_day(int yyy);
int mlensel(int mmm);

int main(void) 
{
	int mmm=0,yyy=0;
	int dtrans=0;
	int srt = 0, len = 0;
	do {
		printf("년, 월을 입력하세요,종료는 0 :");
		scanf("%d %d",&yyy, &mmm);
	
		if(!yyy) {
			
		} 
		else {
			puts("");
			printf("\t\t%d년 %d월\n",yyy,mmm);
			puts("===========================================================");
			puts("-----------------------------------------------------------");
			puts("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\t");
			puts("-----------------------------------------------------------");
			
			//day-transaction part
			dtrans+=(yyy-1)*365;
			dtrans+=(mmm-1)*30;
			
			//month len(29,30,31) selection part 
			dtrans+=mlensel(mmm);
			
			//YUNN-year cale
			dtrans+=yun_year(yyy);
			dtrans-=yun_day(yyy);
			
			//trminal operantion to display cal
			srt = dtrans%7;
			len = monthlen(mmm);
			
			cal(srt,len);
		}
	}while(yyy)	;
	
	puts("종료됨");
	return 0;
}





//======================================
void cal (int srt,int len) 
{
	int i=0, i7=0;
	i7=srt;
	for(i=0;i<srt-1;i++) {
		printf("\t");
	}
	for(i=1 ; i<(len+1) ; i++) {
		printf("%d\t",i);
		i7++;
		if(i7>=8) {
			puts("");
			i7=1;
		}
	}
	puts("");
	puts("");
}

int mlensel(int mmm) 
{
	if( (mmm/2) > 6 ) {
		return -1;
	}
	if(mmm>8) {
		return +1;
	}
	return 0;
}



//============================
//
//========================
int monthlen(int mmm) 
{
	
	if(mmm>=8) {
		if(mmm%2) {
			return 31;		
		}
		else {
			return 30;
		}
	}
	else {
		if(!mmm%2) {
			return 31;		
		}
		else {
			return 30;
		}
	}
}


//============================
//
//==========================
int yun_year(int yyy)
{
	int val=0;
	
	val+=yyy/4;
	val-=yyy/100;
	val-=yyy/400;
	
}


//============================
//
//===========================
int yun_day(int yyy)
{
	if(!(yyy%4)) {
		if(!(yyy%100)) {
			
			if(!(yyy%400)) {
				return 1;
			}
			else {
			}
			return 0;
		}
		else {
		}
		return 1;
	}
	else {
		return 0;	
	}
	return 0;
}
