#include "stdafx.h"
#include <iostream>
using namespace std;

// 초기 제작자
class CMyData
{
public:
	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

// 후기 제작자
class CMyDataEx : public CMyData
{
public:
	// 파생 클래스에서 기본 클래스의 메서드를 재정의했다.
	void SetData(int nParam)
	{
		// 입력 데이터의 값을 보정하는 새로운 기능을 추가한다.
		if (nParam < 0)
			CMyData::SetData(0);

		if (nParam > 10)
			CMyData::SetData(10);
	}
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	// 구형에서는 값을 보정하는 기능이 없다.
	CMyData a;
	a.SetData(-10);
	cout << a.GetData() << endl;

	// 새로 만든 신형에는 값을 보정하는 기능이 있다.
	CMyDataEx b;
	b.SetData(15);
	cout << b.GetData() << endl;

	return 0;
}