#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam)
	{
		m_pnData = new int;
		*m_pnData = nParam;
	}

	// 복사 생성자 선언 및 정의
	CMyData(const CMyData &rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;

		// 메모리를 할당한다.
		m_pnData = new int;

		// 포인터가 가리키는 위치에 값을 복사한다.
		*m_pnData = *rhs.m_pnData;
	}

	// 객체가 소멸하면 동적 할당한 메모리를 해제한다.
	~CMyData()
	{
		delete m_pnData;
	}

	// 단순 대입 연산자 함수를 정의한다.
	CMyData& operator=(const CMyData &rhs)
	{
		*m_pnData = *rhs.m_pnData;

		// 객체 자신에 대한 참조를 반환한다.
		return *this;
	}

	int GetData()
	{
		if (if (m_pnData != NULL)
			return *m_pnData;

		return 0;
	}

private:
	// 포인터 멤버 데이터
	int *m_pnData = nullptr;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData a(10);
	CMyData b(20);

	// 단순 대입을 시도하면 모든 멤버의 값을 그대로 복사한다.
	a = b;
	cout << a.GetData() << endl;

	return 0;
}