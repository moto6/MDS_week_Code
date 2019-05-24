#include <stdio.h>
#include <string.h>

int strtoNum(char *str, int s, int e);
int leap_year(int year);
int formatErrorCheck(char *p_num);
int isY(void);
int vaild_num(char *p_num);
void idCheck(void);

int strtoNum(char *str, int s, int e)
{
	int num = 0;
	int multi = 1;
	int idx;
	int diff = '1' - 1;

	for (idx = e; idx >= s; idx--) {
		num += multi * (str[idx] - diff);
		multi *= 10;
	}
	return num;
}


//KDH : 검증 필요함 -1 
int leap_year(int year)
{
//	int leap = 0;
	
	if(year%4) {
		if(year%100) {
			if(year%400) {
				return 1;
			}
			else {
				return -5000; // Error code
			}
		}
		else {}
		return 1;
	}
	else {
	return 0;	
	}
	return 0;
	// TODO: 이곳에 코드를 작성하세요.
	// 윤년 return =1, 평년 = return 0 
}

int formatErrorCheck(char *p_num)
{
	int dayofmonth[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int check_num;
	int i, mod = 0, sum = 0;
	int year, leap = 0;

	// 주민번호 길이는 13
	if (strlen(p_num) != 13) {
		return 0;
	}
	
	// 월은 12월을 넘어서는 안 된다.
	if (strtoNum(p_num,2,3)>12) {
		return 1;
	}
	
	// 월에 정해진 날짜가 넘어서는 안 된다.
	if (strtoNum(p_num,4,5)>dayofmonth[strtoNum(p_num,4,5)]) {
		return 2;
	}
	// 윤년이면 1
	year = (strtoNum(p_num, 6, 6) <= 2) ? 1900 : 2000;
	year += strtoNum(p_num, 0, 1);
	leap = leap_year(year);
	
	// 2월이고 평년이면 29가 나오면 안 된다.
	// DHKim 주 : 납득할수 없는 조건 -> 평년 2019년의 2월 29일 출생자는 무조건 무효 주민번호? 
	if ( (strtoNum(p_num,2,3) == 2) && (0!=strtoNum(p_num,0,1)%4) && ( strtoNum(p_num,4,5) == 29 ) ) {
		return 3;
	}
	
	if (p_num[6] - '0' < 1 || p_num[6] - '0' > 4) {
		return 4;
	}

	mod = vaild_num(p_num);
	// 주민번호 검증코드(매직넘버) 검사
	if (mod != p_num[12] - '0'){
		return 5;
	}
		

	return -1;
}

int isY(void)
{
	char answer;
	printf("다시 입력하시겠습니까? (y/n) ");
	fflush(stdin);
	scanf("%c", &answer);
	if (answer == 'Y' || answer == 'y')
		return 1;
	return 0;
}



//KDH : 검증 필요함 -1
int vaild_num(char *p_num) 
{
	int i=0,sum=0,rmd_11=0,rmd_10=0;
	for(i=1 ; i<(13+1) ; i++ ) {
		sum += strtoNum(p_num,i,i)*(i+1);	
	}
	rmd_11 = sum%11;
	rmd_10 = (11-rmd_11)%10;
	
	return rmd_10;
}
