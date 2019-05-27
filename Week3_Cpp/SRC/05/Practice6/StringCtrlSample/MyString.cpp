#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString()
: m_pszData(NULL)
, m_nLength(0)
{
}

// 변환 생성자
CMyString::CMyString(const char *pszParam)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(pszParam);
}

// 복사 생성자
CMyString::CMyString(const CMyString &rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	this->SetString(rhs.GetString());
}

// 이동 생성자
CMyString::CMyString(CMyString &&rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	cout << "CMyString 이동 생성자 호출" << endl;

	// 얕은 복사를 수행해도 상관없다. 어차피 원본이 곧 소멸하기 때문이다!
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체의 멤버들은 초기화한다. 절대로 해제하면 안 된다.
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
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

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char * pszParam)
{
	// 매개변수 유효성 검사
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	// 세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리
	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// 현재 문자열의 길이 백업
	int nLenCur = m_nLength;

	// 두 문자열을 합쳐서 저장할 수 있는 메모리를 새로 할당
	char *pszResult = new char[nLenCur + nLenParam + 1];

	// 문자열 조합
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur),
		sizeof(char) * (nLenParam + 1), pszParam);

	// 기존 문자열 삭제 및 멤버 정보 갱신
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString & rhs)
{
	CMyString strResult(m_pszData);
	strResult.Append(rhs.GetString());

	return strResult;
}

CMyString& CMyString::operator+=(const CMyString & rhs)
{
	Append(rhs.GetString());

	return *this;
}