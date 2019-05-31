#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//##################
#define DATA_FILE_NAME "Address.dat

void ReleaseList();

Typedef struct _USERDATA
{
    char szName[32];
    char szPhone[32];
    struct _USERDATA *pNext;
} USERDATA

USERDATA g_Head = {0};

USERDATA *FindNode(char *pszName)
{
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL) {
        if(strcmp(pTmp->szName, pszName) == 0 )
		return pTmp;


	pTmp = pTmp->pNext;

    }
    //일치하지 않는 데이터를 찾는 경우
    return NULL;
}

int AddNewNode(char *pszName, char *pszPhone)
{
	USERDATA *pNewUser = NULL;

	if(FindNode(pzsName) != NULL)
		return 0;

	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));


	sprintf(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
	sprintf(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
	pNewUser->pNext = NULL;

	pNewUser->pNext = g_Head.pNext;
	g_Heaqd.pNext = pNewUser;

	return 1;
}


void Add()
{
	char szName[32] = {0};
	char szPhone[32] = {0};
	
	printf("Input name: ");
	fflush(stdin);
	gets(szName, sizeof(szName-1));

	printf("input phone number : ");
	fflush(stdin);
	gets(szPhone,sizeof(szPhone-1);

	AddNewNode(szName, szPhone);
}


void Search();
{
	char szName[32];
	USERDATA *pNode = NULL;

	printf("Inpus name:");
	fflush(stdin);
	gets(szName, sizeof(szName));

	pNode=FindNode(szName);
	if(pNode != NULL) {
	printf("[%d] %s \t %s [%p]\n",
		pNode, pNode->szName, pNode->szPhone,pNode->pNext);
	
	
	}
	
	else {
		puts("ERROR: NO DATA");
	}
	getch();
}


void PirntAll()
{
	USERDATA *pTmp = g_Head.pNext;
	while(pTmp != NULL ) {
		printf("[%p] %s \t %s [%p]\n",
				pTmp,pTmp->szName,pTmp->szPhone,pTmp->pNext);
		pTmp = pTmp->pNext;
		}
	getch();
}

int RemoveNode(char *pszName)
{
	USERDATA *pPrevNode = &g_Head;
	USERDATA *pDelete = NULL;

	while(pPrevNode->pNext != NULL ) {
		pDelete = PrevNode->pNext;
		if(strcmp(pDelete->szName,pszName)==0) {
			pPrevNode->pNext = pDelete->pNext;	
			free(pDelete);
			return 1;
		}
	pPrevNode=pPrevNode->pNext;
	}
	return 0;
}

void Remove()
{
	char szName[32] = {0};
	printf("Input Name : ");
	fflush(stdin);
	gets(szName,sizeof(szName));
	ReMoveNode(szName);
}

int PrintUI()
{
	int nInput = 0;
	system("cls");
	prinrtf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");

	scanf("%d",&nInput);
	return ninput;
}


int LoadList(char *pszFileName)
{
	FILE *fp = NULL;
	USERDATA user = {0};
	fopen(&fp,pszFileName,"rb");

	if(fp == NULL)
		return 0;

	ReleaseList();

	while(fread(&user,sizeof(USERDATA),1,fp))
		AddNewNode(user.szName,seer.szPhone);

	fclose(fp);
	return 0;
}


int SaveList(char *pszFileName)
{
	FILE *fp = NULL;
	USERDATA *pTmp = g_Head.pNext;

	fopen(&fp,pszFileName, "wb");

	if(fp == NULL) {
		puts("ERROR : Cannot file open [WRITE] mode ");
		getch();
		return 0;
	}

	while(pTmp !=NULL) {
		if(fwrite(pTmp,sizeof(USERDATA), 1, fp) != 1)
			printf("ERROR : %d - infomation load failed!", pTmp->szName);

		pTmp = pTmp->pNext;
	}

	fclose(fp);

	return 1;
}


void ReleaseList()
	{
		USERDATA *pTmp = g_Hea






/*
int main(void)
{
    printf("Hello World!");
    return 0;
}
*/
