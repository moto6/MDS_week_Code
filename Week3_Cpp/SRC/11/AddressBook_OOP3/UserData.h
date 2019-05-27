#pragma once
#include "MyNode.h"

// CMyNode 클래스의 파생 클래스로 변경
class CUserData : public CMyNode
{
public:
	CUserData(void);
	CUserData(const char* pszName, const char* pszPhone);
	~CUserData(void);

	const char* GetName(void) const { return szName; }
	const char*	GetPhone(void) const { return szPhone; }
	static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
	CMyString strName;
	CMyString strPhone;

	// pNext 멤버가 사라졌다.
	static int nUserDataCounter;

public:
	// 순수 가상 함수들 정의
	virtual const char* GetKey(void);
	virtual void PrintNode(void);
};