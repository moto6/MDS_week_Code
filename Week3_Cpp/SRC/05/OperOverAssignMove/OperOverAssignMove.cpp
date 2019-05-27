#include "stdafx.h"
#include <iostream>
using namespace std;


// 제작자 코드
class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		cout << "CMyData(int)" << endl;
		m_pnData = new int(nParam);
	}

	CMyData(const CMyData &rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;
		m_pnData = new int(*rhs.m_pnData);
	}

	~CMyData() { delete m_pnData; }

	operator int() { return *m_pnData; }

	// 덧셈 연산자 다중 정의
	CMyData operator+(const CMyData &rhs)
	{
		// 호출자 함수에서 이름 없는 임시 객체가 생성된다.
		return CMyData(*m_pnData + *rhs.m_pnData);
	}

	// 단순 대입 연산자 오버로딩다중 정의
	CMyData& operator=(const CMyData &rhs)
	{
		cout << "operator=" << endl;
		if (this == &rhs)
			return *this;

		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);

		return *this;
	}

	// 이동 대입 연산자 다중 정의
	CMyData& operator=(CMyData &&rhs)
	{
		cout << "operator = (Move)" << endl;

		// 얕은 복사를 수행하고 원본은 NULL로 초기화한다.
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = NULL;

		return *this;
	}

private:
	int *m_pnData = nullptr;
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(0), b(3), c(4);
	cout << "*****Before*****" << endl;

	// 이동 대입 연산자가 실행된다!
	a = b + c;
	cout << "*****After*****" << endl;
	cout << a << endl;
	a = b;
	cout << a << endl;

	return 0;
}