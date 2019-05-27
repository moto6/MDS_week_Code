#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyStringEx strTest;

	// 문자열이 필터링되어 대체되는 경우
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;

	// 필터링되지 않는 경우
	strTest.SetString("Hello");
	cout << strTest << endl;

	return 0;
}