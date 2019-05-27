#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 100, b;
	cout << "Input number: ";
	cin >> b;

	// 사용자가 입력한 수로 100을 나누고 출력한다.
	cout << a / b << endl;

	return 0;
}