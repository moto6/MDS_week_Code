#include "stdafx.h"
#include <iostream>
using namespace std;

// 'T'는 자료형이 된다.
template<typename T>
class CMyData
{
public:
	CMyData(T param) : m_Data(param) { }
	T GetData() const { return m_Data; }

	// 형식에 대한 변환자 제공
	operator T () { return m_Data; }
	void SetData(T param) { m_Data = param; }

private:
	// T 형식의 멤버 변수 선언
	T m_Data;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyData<int> a(5);
	cout << a << endl;
	CMyData<double> b(123.45);
	cout << b << endl;

	// 문자열을 저장하기 위해 메모리를 동적 할당하지는 않는다.
	CMyData<char*> c("Hello");
	cout << c << endl;

	return 0;
}