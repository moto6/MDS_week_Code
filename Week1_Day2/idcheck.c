/*
 * idcheck.c 
 * modifly by DHKim 2019-05-14
 */

#include "wshop1.h"
/*
 *
int strtoNum(char *str, int s, int e);
int leap_year(int year);
int formatErrorCheck(char *p_num);
int isY(void);
void idCheck(void);
 *
 */
int main(void)
{
	char *errormsg[] = {
			"주민등록번호 길이가 틀렸습니다.",
			"잘못 입력된 월번호입니다.",
			"잘못 입력된 일번호입니다.",
			"평년인데 윤년 날짜입니다.",
			"성별 번호가 잘못 입력되었습니다.",
			"검증코드 오류인 주민등록번호입니다." };
	char p_num[15];
	int errorno = 0;

	do {
		printf("\"-\"를 제외한 확인할 주민등록번호 13자리를 입력하세요 : "); 
		scanf("%s", p_num);

		errorno = formatErrorCheck(p_num);
		if (errorno >= 0)
			printf("%s\n", errormsg[errorno]);
		else
			printf("올바른 주민등록번호입니다.\n");
	} while (isY());

	return 0;
}

