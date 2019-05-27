#include "stdafx.h"
#include <iostream>
using namespace std;

// 매개변수가 int에 대한 참조 형식이다.
void TestFunc(int &rParam)
{
	// 피호출자 함수에서 원본의 값을 변경했다.
	rParam = 100;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nData = 0;

	// 참조에 의한 인수 전달이다.
	TestFunc(nData);
	cout << nData << endl;

	return 0;
}