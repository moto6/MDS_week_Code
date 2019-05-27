#include "stdafx.h"
#include "MyList.h"

CMyList::CMyList(void)
{
}

CMyList::~CMyList(void)
{
	ReleaseList();
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	CUserData *pNewUser = NULL;

	if (FindNode(pszName) != NULL)
		return 0;

	pNewUser = new CUserData;
	strcpy_s(pNewUser->szName, sizeof(pNewUser->szName), pszName);
	strcpy_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), pszPhone);
	pNewUser->pNext = NULL;

	pNewUser->pNext = m_Head.pNext;
	m_Head.pNext = pNewUser;

	return 1;
}

void CMyList::PrintAll(void)
{
	CUserData *pTmp = m_Head.pNext;

	while (pTmp != NULL)
	{
		printf("[%p] %s\t%s [%p]\n",
			pTmp,
			pTmp->szName, pTmp->szPhone,
			pTmp->pNext);

		pTmp = pTmp->pNext;
	}

	printf("CUserData Counter : %d\n", CUserData::GetUserDataCounter());

	_getch();
}

CUserData* CMyList::FindNode(const char* pszName)
{
	CUserData *pTmp = m_Head.pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

int CMyList::RemoveNode(const char* pszName)
{
	CUserData *pPrevNode = &m_Head;
	CUserData *pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

void CMyList::ReleaseList(void)
{
	CUserData *pTmp = m_Head.pNext;
	CUserData *pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_Head.pNext = NULL;
}