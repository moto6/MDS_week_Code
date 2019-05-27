#include "stdafx.h"
#include <iostream>
using namespace std;

// 전역(개념상 무소속)
void TestFunc(void) { cout << "::TestFunc()" << endl; }

namespace TEST
{
	// TEST 네임스페이스 소속
	void TestFunc(void) {
		cout << "TEST::TestFunc()" << endl;
	}
}

namespace MYDATA
{
	// MYDATA 네임스페이스 소속
	void TestFunc(void) {
		cout << "DATA::TestFunc()" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestFunc();          // 묵시적 전역
	::TestFunc();        // 명시적 전역
	TEST::TestFunc();
	MYDATA::TestFunc();

	return 0;
}