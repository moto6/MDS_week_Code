#include "stdafx.h"
#include "MyStringEx.h"

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::~CMyStringEx()
{
}

int CMyStringEx::Find(const char * pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;

	const char *pszResult = strstr(GetString(), pszParam);

	if (pszResult != NULL)
		return pszResult - GetString();

	return -1;
}