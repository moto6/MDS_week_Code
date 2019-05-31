#pragma once
#include "MyNode.h"
#include "MyIterator.h"
//#include "MyList.cpp"

class CMyList
{
public:
	CMyList(CMyNode *pHead);
	//CMyList();
	~CMyList(void);

protected:
	void ReleaseList(void);
	CMyNode *m_pHead;

public:
	CMyNode* FindNode(const char* pszKey);
	int AddNewNode(CMyNode *pNewNode);
	//UI코드이다. 설계상 바람직하지 않다.
//	void PrintAll(void);
	int RemoveNode(const char* pszKey);
	CMyIterator MakeIterator(void);

	virtual int OnAddNewNode(CMyNode* pNewNode);
};
