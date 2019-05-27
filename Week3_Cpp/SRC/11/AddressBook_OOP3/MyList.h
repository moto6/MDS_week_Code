#pragma once
#include "MyNode.h"
#include "MyIterator.h"

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	~CMyList(void);

protected:
	void ReleaseList(void);
	CMyNode *m_pHead;

public:
	CMyNode* FindNode(const char* pszKey);
	int AddNewNode(CMyNode *pNewNode);

	// UI 코드. 설계상 바람직하지 않다.
	// void PrintAll(void);
	int RemoveNode(const char* pszKey);

	// 열거자를 생성한다.
	CMyIterator MakeIterator(void);

	// 데이터가 추가될 때마다 호출되는 가상 함수
	virtual int OnAddNewNode(CMyNode* pNewNode);
};