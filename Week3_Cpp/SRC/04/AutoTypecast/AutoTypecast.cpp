#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 코드
class CTestData
{
public:
	explicit CTestData(int nParam) : m_nData(nParam) { }

	// CTestData 클래스는 int 자료형식으로 변환될 수 있다!
	operator int(void) { return m_nData; }

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CTestData a(10);
	cout << a.GetData() << endl;

	// CTestData 형식에서 int 자료형으로 변환될 수 있다.
	cout << a << endl;
	cout << (int)a << endl;
	cout << static_cast<int>(a) << endl;

	return 0;
}