#pragma once
#include "MyNode.h"

// 노드 클래스에 대한 알림 선언
class CMyNode;

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
	void PrintAll(void);
	int RemoveNode(const char* pszKey);
};