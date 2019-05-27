#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 코드
class CTestData
{
public:
	CTestData(int nParam, char *pszName) : m_nData(nParam), m_pszName(pszName)
	{
		cout << "CTestData(int): " << m_pszName << endl;
	}

	~CTestData()
	{
		cout << "~CTestData(): " << m_pszName << endl;
	}

	CTestData(const CTestData &rhs) : m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
	{
		cout << "CTestData(const CTestData &): " << m_pszName << endl;
	}

	CTestData& operator=(const CTestData &rhs)
	{
		cout << "operator=" << endl;

		// 값은 변경하지만 이름(m_pszName)은 그대로 둔다.
		m_nData = rhs.m_nData;

		return *this;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;

	// 변수 이름을 저장하기 위한 멤버
	char *m_pszName = nullptr;
};

// CTestData 객체를 반환하는 함수다.
CTestData TestFunc(int nParam)
{
	// CTestData 클래스 인스턴스인 a는 지역변수지역 변수다.
	// 따라서 함수가 반환되면 소멸한다.
	CTestData a(nParam, "a");

	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CTestData b(5, "b");
	cout << "*****Before*****" << endl;

	// 함수가 반환하면서 임시 객체가 생성됐다가 대입 연산 후 즉시 소멸한다!
	b = TestFunc(10);
	cout << "*****After*****" << endl;
	cout << b.GetData() << endl;

	return 0;
}