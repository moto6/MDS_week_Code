#include "stdafx.h"
#include "MyString.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strLeft("Hello"), strRight("World"), strResult;
	strResult = strLeft + strRight;
	cout << strResult << endl;

	cout << strLeft << endl;
	strLeft += CMyString("World");
	cout << strLeft << endl;

	return 0;
}