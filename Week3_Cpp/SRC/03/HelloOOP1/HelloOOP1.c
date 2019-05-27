#include <stdio.h>

// 제작자의 코드
typedef struct USERDATA
{
	int nAge;
	char szName[32];
} USERDATA;

// 사용자의 코드
int main(void)
{
	USERDATA user = { 20, "철수" };
	printf("%d, %s\n", user.nAge, user.szName);

	return 0;
}