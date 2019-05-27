#include "stdafx.h"
#include <iostream>
using namespace std;

// 참조 전달이므로 호출자 변수의 값을 변경할 수 있다.
void Swap(int &a, int &b)
{
	int nTmp = a;
	a = b;
	b = nTmp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 10, y = 20;

	// 참조 전달이며 두 변수의 값이 교환된다.
	Swap(x, y);

	// 교환된 결과를 출력한다.
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	return 0;
}