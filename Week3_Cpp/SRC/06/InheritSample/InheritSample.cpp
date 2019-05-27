#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 - 초기 개발자
class CMyData
{
public:		  // 누구나 접근 가능
	CMyData() { cout << "CMyData()" << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

protected:	  // 파생 클래스만 접근 가능
	void PrintData() { cout << "CMyData::PrintData()" << endl; }

private:	  // 누구도 접근 불가능
	int m_nData = 0;
};

// 제작자 - 후기 개발자
class CMyDataEx : public CMyData
{
public:
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	void TestFunc()
	{
		// 기본 형식 멤버에 접근
		PrintData();
		SetData(5);
		cout << CMyData::GetData() << endl;
	}
};

// 사용자
int _tmain(int argc, _TCHAR* argv[])
{
	CMyDataEx data;

	// 기본 클래스(CMyData) 멤버에 접근
	data.SetData(10);
	cout << data.GetData() << endl;

	// 파생 클래스(CMyDataEx) 멤버에 접근
	data.TestFunc();

	return 0;
}