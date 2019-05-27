#include "stdafx.h"
#include "MyStringEx.h"

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::CMyStringEx(const char * pszParam)
	: CMyString(pszParam)
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

int CMyStringEx::SetString(const char * pszParam)
{
	int nResult;

	if (strcmp(pszParam, "¸Û¸ÛÀÌ¾Æµé") == 0)
		nResult = CMyString::SetString("ÂøÇÑ»ç¶÷");

	else
		nResult = CMyString::SetString(pszParam);

	return nResult;
}