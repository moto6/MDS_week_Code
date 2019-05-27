#include "stdafx.h"
#include <iostream>
using namespace std;

class CmyCMyData
{
public:
	CmyCMyData(int nParam) : m_nData(nParam) {}{}

	// 형변환
	operator int() { return m_nData; }

	// 전위 증가 연산자
	int operator++()
	{
		cout << "operator++()" << endl;
		return ++m_nData;
	}

	// 후위 증가 연산자
	int operator++(int)
	{
		cout << "operator++(int)" << endl;
		int nData = m_nData;
		m_nData++;

		return nData;
	}

private:
	int m_nData = 0;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CmyCMyData a(10);

	// 전위 증가 연산자를 호출한다.
	cout << ++a << endl;

	// 후위 증가 연산자를 호출한다.
	cout << a++ << endl;
	cout << a << endl;

	return 0;
}