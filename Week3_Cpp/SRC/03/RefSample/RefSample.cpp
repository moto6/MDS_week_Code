#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 코드
class CRefTest
{
public:
	// 참조형 멤버는 반드시 생성자 초기화 목록을 이용해 초기화한다.
	CRefTest(int &rParam) : m_nData(rParam) { };
	int GetData(void) { return m_nData; }

private:
	// 참조형 멤버는 객체가 생성될 때 반드시 초기화해야 한다.
	int &m_nData;
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 10;
	CRefTest t(a);

	cout << t.GetData() << endl;

	// 참조 원본인 a의 값이 수정됐다.
	a = 20;
	cout << t.GetData() << endl;

	return 0;
}