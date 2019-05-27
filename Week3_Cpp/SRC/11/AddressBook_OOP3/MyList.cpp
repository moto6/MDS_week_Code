#include "stdafx.h"
#include "MyList.h"
#include "UserData.h"

CMyList::CMyList(CMyNode *pHead)
{
	m_pHead = pHead;
}

CMyList::~CMyList(void)
{
	ReleaseList();
}

int CMyList::AddNewNode(CMyNode *pNewNode)
{
	if (FindNode(pNewNode->GetKey()) != NULL)
	{
		delete pNewNode;

		return 0;
	}

	if(OnAddNewNode(pNewNode))
	{
		pNewNode->pNext = m_pHead->pNext;
		m_pHead->pNext = pNewNode;

		return 1;
	}

	return -1;
}

/*
void CMyList::PrintAll(void)
{
	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != NULL)
	{
		pTmp->PrintNode();
		pTmp = pTmp->pNext;
	}

	printf("CUserData Counter : %d\n", CUserData::GetUserDataCounter());

	_getch();
}
*/

CMyNode* CMyList::FindNode(const char* pszKey)
{
	CMyNode *pTmp = m_pHead->pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->GetKey(), pszKey) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

int CMyList::RemoveNode(const char* pszKey)
{
	CMyNode *pPrevNode = m_pHead;
	CMyNode *pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->GetKey(), pszKey) == 0)
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
	CMyNode *pTmp = m_pHead;
	CMyNode *pDelete = NULL;

	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_pHead = NULL;
}

CMyIterator CMyList::MakeIterator(void)
{
	CMyIterator it;
	it.m_pCurrent = m_pHead->pNext;
	it.m_pHead = m_pHead->pNext;

	return it;
}

int CMyList::OnAddNewNode(CMyNode* pNewNode)
{
	return 1;
}