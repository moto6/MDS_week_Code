#include "stdafx.h"
#include <iostream>
using namespace std;

class CTest
{
public:
	CTest(int nParam) : m_nData(nParam) { };
	~CTest() { }

	// 상수형 메서드로 선언 및 정의했다.
	int GetData() const
	{
		// 상수형 메서드라도 mutable 멤버 변수에는 값을 쓸 수 있다.
		m_nData = 20;
		return m_nData;
	}

	int SetData(int nParam) { m_nData = nParam; }

private:
	mutable int m_nData = 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest a(10);
	cout << a.GetData() << endl;

	return 0;
}