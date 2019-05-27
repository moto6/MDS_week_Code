#include "stdafx.h"
#include <iostream>
using namespace std;

// 템플릿 매개변수를 함수처럼 선언한다.
template<typename T, int nSize>
class CMyArray
{
public:
	// 이하 코드에 보이는 모든 nSize 변수는 템플릿 매개변수다.
	CMyArray() { m_pData = new T[nSize]; }
	~CMyArray() { delete[] m_pData; }

	// 배열 연산자
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= nSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	// 상수화된 배열 연산자 
	T& operator[](int nIndex) const { return operator[](nIndex); }

	// 배열 요소의 개수를 반환
	int GetSize() { return nSize; }

private:
	T *m_pData = nullptr;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyArray<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	for (for (int i = 0; i < 3; ++i)
		cout << arr[i] << endl;

	return 0;
}