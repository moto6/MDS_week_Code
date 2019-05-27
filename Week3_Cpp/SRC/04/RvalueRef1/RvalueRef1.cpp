#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int&& data = 3 + 4;
	cout << data << endl;
	data++;
	cout << data << endl;

	return 0;
}