#include "stdafx.h"
#include <iostream>
using namespace std;

// 최초 설계자 코드
class CMyInterface
{
public:
	CMyInterface()
	{
		cout << "CMyInterface()" << endl;
	}

	// 선언만 있고 정의는 없는 순수 가상 함수
	virtual int GetData() const = 0;
	virtual void SetData(int nParam) = 0;
};

// 후기 개발자 코드
class CMyData : public CMyInterface
{
public:
	CMyData() { cout << "CMyData()" << endl; }

	// 순수 가상 함수는 파생 클래스에서 '반드시' 정의해야 한다.
	virtual int GetData() const { return m_nData; }
	virtual void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	// 순수 가상 클래스는 인스턴스를 선언 및 정의할 수 없다.
	// CMyInterface a;
	CMyData a;
	a.SetData(5);
	cout << a.GetData() << endl;

	return 0;
}