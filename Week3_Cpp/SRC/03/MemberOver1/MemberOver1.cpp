#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 코드
class CMyData
{
public:
	CMyData() : m_nData(0) { };

	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// 매개변수가 double 자료형인 경우로 다중 정의했다.
	void SetData(double dParam) { m_nData = 0; }

private:
	int m_nData;
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a;

	// CMyData::SetData(int) 메서드가 호출된다.
	a.SetData(10);
	cout << a.GetData() << endl;

	CMyData b;

	// CMyData::SetData(double) 메서드가 호출된다.
	b.SetData(5.5);
	cout << b.GetData() << endl;

	return 0;
}