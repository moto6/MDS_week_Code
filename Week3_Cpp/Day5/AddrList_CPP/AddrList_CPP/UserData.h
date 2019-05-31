#pragma once
#include "MyNode.h"

class CUserData : public CMyNode
{
public:
	CUserData(void);
	~CUserData(void);

	const char*			GetName(void) const		{ return strName; }
	const char*			GetPhone(void) const	{ return strPhone; }
	static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
	CMyString strName;
	CMyString strPhone;

	static int nUserDataCounter;
public:
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
	CUserData(const char* pszName, const char* pszPhone);
};
