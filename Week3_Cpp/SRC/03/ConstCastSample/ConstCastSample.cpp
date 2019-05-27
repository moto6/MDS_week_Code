#include "stdafx.h"
#include <iostream>
using namespace std;

void TestFunc(const int &nParam)
{
	// 상수형 참조였으나 일반 참조로 형변환했다.
	int &nNewParam = const_cast<int &> (nParam);

	// 따라서 l-value가 될 수 있다.
	nNewParam = 20;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 10;

	// 상수형 참조로 전달하지만 값이 변경된다.
	TestFunc(nData);

	// 변경된 값을 출력한다.
	cout << nData << endl;

	return 0;
}