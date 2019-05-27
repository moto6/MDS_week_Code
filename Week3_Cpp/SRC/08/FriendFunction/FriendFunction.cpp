#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) { }
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// friend 함수로 선언한다.
	friend void PrintData(const CMyData &);

private:
	int m_nData = 0;
};

void PrintData(const CMyData &rData)
{
	// 프렌드 함수이므로 접근 제어 지시자의 영향을 받지 않고
	// private 멤버에 직접 접근한다.
	cout << "PrintData(): " << rData.m_nData << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(5);
	PrintData(a);

	return 0;
}