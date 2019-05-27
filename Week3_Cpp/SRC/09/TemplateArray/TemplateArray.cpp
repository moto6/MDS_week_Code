#include "stdafx.h"
#include <iostream>
using namespace std;

template<typename T>
class CMyArray
{
public:
	explicit CMyArray(int nSize) : m_nSize(nSize)
	{
		m_pData = new T[nSize];
	}

	~CMyArray() { delete[] m_pData; }

	// 복사 생성자
	CMyArray(const CMyArray &rhs)
	{
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T)* rhs.m_nSize);
		m_nSize = rhs.m_nSize;
	}

	// 대입 연산자
	CMyArray& operator=(const CMyArray &rhs)
	{
		if (this == &rhs)
			return *this;

		delete m_pData;
		m_pData = new T[rhs.m_nSize];
		memcpy(m_pData, rhs.m_pData, sizeof(T)* rhs.m_nSize);
		m_nSize = rhs.m_nSize;

		return *this;
	}

	// 이동 생성자
	CMyArray(CMyArray &&rhs)
	{
		operator = (rhs);
	}

	// 이동 대입 연산자
	CMyArray& operator=(const CMyArray &&rhs)
	{
		m_pData = rhs.m_pData;
		m_nSize = rhs.m_nSize;
		rhs.m_pData = nullptr;
		rhs.m_nSize = 0;
	}

	// 배열 연산자
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}

		return m_pData[nIndex];
	}

	// 상수화된 배열 연산자 
	T& operator[](int nIndex) const
	{
		return operator[](nIndex);
	}

	// 배열 요소의 개수를 반환
	int GetSize() { return m_nSize; }

private:
	T *m_pData = nullptr;
	int m_nSize = 0;
};

int _tmain(int argc, _TCHAR* argv[])
{
	// int 자료형 배열
	CMyArray<int> arr(5);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';

	cout << endl;

	CMyArray<int> arr2(3);
	arr2 = arr;
	for (int i = 0; i < 5; ++i)
		cout << arr2[i] << ' ';

	cout << endl;

	return 0;
}