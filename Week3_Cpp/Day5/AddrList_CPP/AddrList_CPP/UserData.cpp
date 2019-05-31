#include "StdAfx.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void)
{
	nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone)
: strName(pszName), strPhone(pszPhone)
{
	nUserDataCounter++;
}

CUserData::~CUserData(void)
{
	nUserDataCounter--;
}


const char* CUserData::GetKey(void)
{
	return (const char*)strName;
}

void CUserData::PrintNode(void)
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n",
		this,
		(const char*)strName,
		(const char*)strPhone,
		GetNext() );
#else
	printf("%s\t%s\n",szName, szPhone);
#endif
}
