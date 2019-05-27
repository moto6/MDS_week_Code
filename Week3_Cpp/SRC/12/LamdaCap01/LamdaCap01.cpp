#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 10;
	cout << nData << endl;
	auto TestFunc = [nData](void)->void
	{
		cout << nData << endl;
	};

	TestFunc();

	return 0;
}