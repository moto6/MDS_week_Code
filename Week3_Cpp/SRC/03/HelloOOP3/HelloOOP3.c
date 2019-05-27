#include <stdio.h>

// 제작자의 코드
typedef struct USERDATA
{
	int nAge;
	char szName[32];
	void(*Print)(struct USERDATA *);
} USERDATA;

void PrintData(USERDATA *pUser)
{
	printf("%d, %s\n", pUser->nAge, pUser->szName);
}

// 사용자의 코드
int main(void)
{
	USERDATA user = { 20, "철수", PrintData };
	// printf("%d, %s\n", user.nAge, user.szName);     // 1단계
	// PrintData(&user);                               // 2단계
	user.Print(&user);                                 // 3단계

	return 0;
}