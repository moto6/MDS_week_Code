#pragma once
#include "MyNode.h"
#include <iostream>

class CMyIterator
{
	friend class CMyList;
public:
	CMyIterator(void);
	~CMyIterator(void);

	CMyNode* GetCurrent(void) const { return m_pCurrent; }
	void MoveNext(void)
	{
		if(m_pCurrent != NULL)
			m_pCurrent = m_pCurrent->pNext;
	}

private:
	CMyNode *m_pHead;
	CMyNode *m_pCurrent;
};
