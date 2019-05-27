#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	// 생성자의 매개변수로 전달된 값으로 멤버 변수를 초기화한다.
	CTest(int nParam) : m_nData(nParam)
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		// 생성할 때 매개변수로 받은 값을 출력한다.
		cout << "~CTest::CTest() " << m_nData << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Begin" << endl;
	CTest a(1);
	cout << "Before b" << endl;
	CTest b(2);
	cout << "End" << endl;

	return 0;
}