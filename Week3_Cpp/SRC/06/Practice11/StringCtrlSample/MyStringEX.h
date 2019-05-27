#pragma once
#include "MyString.h"

class CMyStringEx
	: public CMyString
{
public:
	CMyStringEx();
	CMyStringEx(const char * pszParam);
	~CMyStringEx();
	int Find(const char * pszParam);
	int SetString(const char * pszParam);
};