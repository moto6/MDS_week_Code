#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////////////////////////
// 주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "Address.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char szName[32];	  // 이름
	char szPhone[32];	  // 전화번호

	struct _USERDATA *pNext;
} USERDATA;

// 더미 헤드 노드 선언 및 정의
USERDATA g_Head = { 0 };

/////////////////////////////////////////////////////////////////////////
// 리스트에서 이름으로 특정 노드를 검색하는 함수
USERDATA *FindNode(char *pszName)
{
	USERDATA *pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// 다음 노드로 이동
		pTmp = pTmp->pNext;
	}

	// 일치하는 데이터를 찾지 못한 경우
	return NULL;
}

/////////////////////////////////////////////////////////////////////////
int AddNewNode(char *pszName, char *pszPhone)
{
	USERDATA *pNewUser = NULL;

	// 같은 이름이 이미 존재하는지 확인한다.
	if (FindNode(pszName) != NULL)
		return 0;

	// 메모리를 확보한다.
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	// 메모리에 값을 저장한다.
	sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
	sprintf_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
	pNewUser->pNext = NULL;

	// 더미 노드 바로 뒤에 붙인다. 따라서 가장 최근에
	// 추가한 데이터가 가장 앞쪽에 온다. 
	pNewUser->pNext = g_Head.pNext;
	g_Head.pNext = pNewUser;

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 리스트에 추가하는 함수
void Add()
{
	char szName[32] = { 0 };
	char szPhone[32] = { 0 };

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("Input phone number : ");
	fflush(stdin);
	gets_s(szPhone, sizeof(szPhone));

	// 실제로 리스트에 추가한다.
	AddNewNode(szName, szPhone);
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하는 함수
void Search()
{
	char szName[32] = { 0 };
	USERDATA *pNode = NULL;

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = FindNode(szName);
	if (pNode != NULL) {
		printf("[%p] %s\t%s [%p]\n",
			pNode,
			pNode->szName, pNode->szPhone,
			pNode->pNext);
	}

	else {
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	}

	_getch();
}

/////////////////////////////////////////////////////////////////////////
// 리스트에 들어있는 모든 데이터를 화면에 출력하는 함수
void PrintAll()
{
	USERDATA *pTmp = g_Head.pNext;
	while (pTmp != NULL) {
		printf("[%p] %s\t%s [%p]\n",
			pTmp,
			pTmp->szName, pTmp->szPhone,
			pTmp->pNext);

		pTmp = pTmp->pNext;
	}

	_getch();
}

/////////////////////////////////////////////////////////////////////////
// 특정 노드를 검색하고 삭제하는 함수
int RemoveNode(char *pszName)
{
	USERDATA *pPrevNode = &g_Head;
	USERDATA *pDelete = NULL;

	while (pPrevNode->pNext != NULL) {
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0) {
			pPrevNode->pNext = pDelete->pNext;
			free(pDelete);

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////
// 이름을 입력받아 자료를 검색하고 삭제하는 함수
void Remove()
{
	char szName[32] = { 0 };

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	RemoveNode(szName);
}

/////////////////////////////////////////////////////////////////////////
// 메뉴를 출력하는 UI 함수
int PrintUI()
{
	int nInput = 0;

	system("cls");
	printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d", &nInput);

	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// 데이터 파일에서 노드들을 읽어와 리스트를 완성하는 함수
int LoadList(char *pszFileName)
{
	FILE *fp = NULL;
	USERDATA user = { 0 };

	fopen_s(&fp, pszFileName, "rb");

	if (fp == NULL)
		return 0;

	ReleaseList();

	while (fread(&user, sizeof(USERDATA), 1, fp))
		AddNewNode(user.szName, user.szPhone);

	fclose(fp);

	return 0;
}

/////////////////////////////////////////////////////////////////////////
// 리스트 형태로 존재하는 정보를 파일에 저장하는 함수
int SaveList(char *pszFileName)
{
	FILE *fp = NULL;
	USERDATA *pTmp = g_Head.pNext;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL) {
		puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
		_getch();

		return 0;
	}

	while (pTmp != NULL) {
		if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR: %s에 대한 정보를 저장하는데 실패했습니다.\n", pTmp->szName);

		pTmp = pTmp->pNext;
	}

	fclose(fp);

	return 1;
}

/////////////////////////////////////////////////////////////////////////
// 리스트의 모든 데이터를 삭제하는 함수
void ReleaseList()
{
	USERDATA *pTmp = g_Head.pNext;
	USERDATA *pDelete = NULL;

	while (pTmp != NULL) {
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		free(pDelete);
	}

	memset(&g_Head, 0, sizeof(USERDATA));
}

/////////////////////////////////////////////////////////////////////////
void main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	// 메인 이벤트 반복문
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu)	{
		case 1:		  // Add
			Add();
			break;

		case 2:		  // Search
			Search();
			break;

		case 3:		 // Print all
			PrintAll();
			break;

		case 4:		  // Remove
			Remove();
			break;
		}
	}

	// 종료 전에 파일로 저장하고 메모리를 해제한다.
	SaveList(DATA_FILE_NAME);
	ReleaseList();
}