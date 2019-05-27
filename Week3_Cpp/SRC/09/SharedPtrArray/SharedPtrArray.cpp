#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

void RemoveTest(CTest *pTest)
{
	cout << "RemoveTest()" << endl;

	// 대상을 배열로 삭제한다.
	delete[] pTest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;

	// 대상 객체를 소멸할 함수를 별도로 등록했다.
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
	cout << "******End******" << endl;

	return 0;
}