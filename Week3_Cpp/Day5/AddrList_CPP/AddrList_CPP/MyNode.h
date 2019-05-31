#pragma once

class CMyNode
{
	friend class CMyList;
	friend class CMyIterator;
public:
	CMyNode(void);
	virtual ~CMyNode(void);

	CMyNode* GetNext(void) const { return pNext; }

	virtual const char* GetKey(void) = 0;
	virtual void PrintNode(void) = 0;

private:
	CMyNode *pNext;
};
