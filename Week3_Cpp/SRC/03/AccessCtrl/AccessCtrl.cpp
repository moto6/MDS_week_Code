#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 코드
class CMyData
{
	// 기본 접근 제어 지시자는 'private'이다.
	int m_nData;

public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData data;
	data.SetData(10);
	cout << data.GetData() << endl;

	return 0;
}