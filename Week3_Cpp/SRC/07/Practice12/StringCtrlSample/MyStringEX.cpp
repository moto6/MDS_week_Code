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

void OnSetString(char * pszData, int nLength)
{
	if (strcmp(pszData, "¸Û¸ÛÀÌ¾Æµé") == 0)
		strcpy_s(pszData, sizeof(char)* (nLength + 1), "*ÂøÇÑ¾Æµé*");
}