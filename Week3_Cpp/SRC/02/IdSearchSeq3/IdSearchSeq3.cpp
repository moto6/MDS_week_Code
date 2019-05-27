#include "stdafx.h"
#include <iostream>
using namespace std;

int nData = 200;

namespace TEST
{
	int nData = 100;
	void TestFunc(void)
	{
		cout << nData << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	TEST::TestFunc();

	return 0;
}