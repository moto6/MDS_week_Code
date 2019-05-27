#include "stdafx.h"
#include "MyString.h"

void TestFunc(const CMyString &strParam)
{
	cout << strParam << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strData("Hello");

	::TestFunc(strData);
	::TestFunc(CMyString("World"));

	return 0;
}