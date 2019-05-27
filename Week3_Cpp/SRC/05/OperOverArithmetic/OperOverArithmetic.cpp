#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	// 변환 생성자
	CMyData(int nParam) : m_nData(nParam) {
		cout << "CMyData(int)" << endl;
	}

	// 복사 생성자
	CMyData(const CMyData &rhs) : m_nData(rhs.m_nData)
	{
		cout << "CMyData(const CMyData &)" << endl;
	}

	// 이동 생성자
	CMyData(const CMyData &&rhs) : m_nData(rhs.m_nData)
	{
		cout << "CMyData(const CMyData &&)" << endl;
	}

	// 형변환
	operator int() { return m_nData; }

	// +
	CMyData operator+(const CMyData &rhs)
	{
		cout << "operator+" << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;

		return result;
	}

	// =
	CMyData& operator=(const CMyData &rhs)
	{
		cout << "operator=" << endl;
		m_nData = rhs.m_nData;

		return *this;
	}

private:
	int m_nData = 0;
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	CMyData a(0), b(3), c(4);

	// b + c 연산을 실수행하면 이름 없는 임시 객체가 만들어지며
	// a에 대입하는 것은 이 임시 객체다.
	a = b + c;
	cout << a << endl;
	cout << "******End******" << endl;

	return 0;
}