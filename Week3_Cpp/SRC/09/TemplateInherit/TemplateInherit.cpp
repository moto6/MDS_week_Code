#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
class CMyData
{
public:

protected:
	T m_Data;
};

template<typename T>
class CMyDataEx : public CMyData<T>
{
public:
	T GetData() const { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyDataEx<int> a;
	a.SetData(5);
	cout << a.GetData() << endl;

	return 0;
}