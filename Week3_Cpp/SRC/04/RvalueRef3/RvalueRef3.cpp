#include "stdafx.h"
#include <iostream>
using namespace std;

// r-value 참조 형식
void TestFunc(int &&rParam)
{
	cout << "TestFunc(int &&)" << endl;
}
// r-value 참조 형식과 호출자 코드가 같다.
void TestFunc(int nParam)
{
	cout << "TestFunc(int)" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 모호한 호출이다. int형과 int&&형 모두 가능하다!
	TestFunc(3 + 4);

	return 0;
}