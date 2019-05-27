#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 10, y = 20;

	auto TestFunc = [x, y]()->int
	{
		return x + y;
	};

	cout << TestFunc() << endl;

	return 0;
}