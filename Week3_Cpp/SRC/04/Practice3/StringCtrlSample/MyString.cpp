#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString()
: m_pszData(NULL)
, m_nLength(0)
{
}

// 복사 생성자
CMyString::CMyString(const CMyString &rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::~CMyString()
{
	// 객체가 소멸하기 전에 메모리를 해제한다.
	Release();
}

int CMyString::SetString(const char* pszParam)
{
	// 새로운 문자열 할당에 앞서 기존 정보를 해제한다.
	Release();

	// NULL을 인수로 함수를 호출했다는 것은 메모리를 해제하고
	// NULL로 초기화하는 것으로 볼 수 있다.
	if (pszParam == NULL)
		return 0;

	// 길이가 0인 문자열도 초기화로 인식하고 처리한다.
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	// 문자열의 끝인 NULL 문자를 고려해 메모리를 할당한다.
	m_pszData = new char[nLength + 1];

	// 새로 할당한 메모리에 문자열을 저장한다.
	strcpy_s(m_pszData, sizeof(char)* (nLength + 1), pszParam);
	m_nLength = nLength;

	// 문자열의 길이를 반환한다.
	return nLength;
}

const char* CMyString::GetString() const
{
	return m_pszData;
}

void CMyString::Release()
{
	// 이 함수가 여러번 호출될 경우를 고려해 주요 멤버를 초기화한다.
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString & rhs)
{
	// 자기 자신에 대한 대입이면 아무것도 하지 않는다.
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}