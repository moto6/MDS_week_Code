#pragma once
#include "mylist.h"

class CMyListEx :
	public CMyList
{
public:
	CMyListEx(CMyNode *pHead);
	~CMyListEx(void);
	virtual int OnAddNewNode(CMyNode* pNewNode);
};
