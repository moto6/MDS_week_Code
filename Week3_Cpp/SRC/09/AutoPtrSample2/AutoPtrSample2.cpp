#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
	void TestFunc() { cout << "CMyData::TestFunc()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	auto_ptr<CMyData> ptrTest(new CMyData);
	auto_ptr<CMyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	// 포인터를 대입하면 원본 포인터는 NULL이 된다.
	ptrNew = ptrTest;
	cout << "0x" << ptrTest.get() << endl;

	// 따라서 이 코드를 실행할 수 없다.
	ptrTest->TestFunc();

	return 0;
}