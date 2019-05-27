#include "stdafx.h"
#include "MyString.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyString strLeft("Test"), strRight("String");

	if (strLeft == strRight)
		cout << "Same" << endl;

	else
		cout << "Different" << endl;

	strLeft = CMyString("String");

	if (strLeft != strRight)
		cout << "Different" << endl;

	else
		cout << "Same" << endl;

	return 0;
}