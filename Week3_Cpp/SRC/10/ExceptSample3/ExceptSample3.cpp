#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 100, b;
	cout << "Input number: ";
	cin >> b;

	try
	{
		// 예외를 검사하고 '던진다'.
		if (b == 0)
			throw b;

		else
			cout << a / b << endl;
	}

	catch (int nExp)
	{
		// 예외를 받아 처리한다.
		cout << "ERROR: " << nExp << "으로 나눌 수 없습니다." << endl;
	}

	return 0;
}