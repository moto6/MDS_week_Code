#include "StdAfx.h"
#include "MyString.h"

CMyString::CMyString(void)
: m_pszData(NULL), m_nLength(0)
{
//	cout << "CMyString()" << endl;
}

CMyString::CMyString(const char* pszParam)
: m_pszData(NULL), m_nLength(0)
{
//	cout << "CMyString(const char*)" << endl;
	SetString( pszParam );
}

CMyString::CMyString(const CMyString & rhs)
: m_pszData(NULL), m_nLength(0)
{
//	cout << "CMyString(const CMyString &)" << endl;
	this->SetString( rhs.m_pszData );
}

CMyString::~CMyString(void)
{
//	cout << "~CMyString()" << endl;
	Release();
}

int CMyString::SetString(const char * pszParam)
{
	Release();
	if(pszParam == NULL)	return 0;

	//1. 매개변수로 전달된 문자열의 길이 측정.
	m_nLength = strlen(pszParam);
	if(m_nLength == 0)		return 0;

	//2. 매개변수로 전달된 문자열이 저장될 수 있는
	//	 메모리 동적 할당.
//	m_pszData = (char*)calloc( m_nLength + 1, sizeof(char) );
	m_pszData = new char [m_nLength + 1];
	//3. 동적 할당한 메모리에 문자열 저장.
	strcpy_s(m_pszData, sizeof(char) * (m_nLength + 1), pszParam);

	//미래의 코드를 실행.
	OnSetString(m_pszData);

	//고민1. 만일 매개변수가 NULL이거나 문자열의 길이가
	//		  0이라면, 어떤 처리가 적절한가?
	//고민2. 동적 할당된 메모리는 언제 어디서 해제하는가.
	//고민3. 만일 사용자에 의해 이 함수가 2회 호출된다면
	//		  지금 작성한 코드에 문제는 없는가?
	return m_nLength;
}

void CMyString::Release(void)
{
	//1. m_pszData멤버가 가리키는 메모리를 해제.
	delete [] m_pszData;
	//2. 메서스의 절차상의 호출 순서는 사용자가
	//	 결정한다. 그러므로 메모리를 해제한
	//	 이후로 어떤 코드가 추가되어야 이어지는
	//	 사용자 코드의 절차상 흐름이 문제가
	//	 되지 않을 수 있는가?
	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator =(const CMyString &strParam)
{
	if(this != &strParam)
		SetString(strParam.m_pszData);

	return *this;
}

CMyString& CMyString::operator =(const char * pszParam)
{
	if(this->m_pszData != pszParam)
		SetString(pszParam);

	return *this;
}

CMyString CMyString::operator +(const CMyString & rhs)
{
	CMyString strResult(*this);
	strResult.Append(rhs.m_pszData);
	return strResult;
}

int CMyString::Append(const char* pszParam)
{
	if(pszParam == NULL)	return 0;

	int nLenParam = strlen(pszParam);
	if(nLenParam == 0)		return 0;

	if(m_pszData != NULL)
	{
		int nLenResult = m_nLength + nLenParam;
		char *pszResult = new char[nLenResult + 1];
		strcpy_s(pszResult, m_nLength + 1, m_pszData);
		strcpy_s(pszResult + m_nLength, nLenParam + 1, pszParam);

		Release();
		m_pszData = pszResult;
		m_nLength = nLenResult;
	}
	else
	{
		this->operator = (pszParam);
	}
	return 0;
}

CMyString CMyString::operator +(const char* pszParam)
{
	CMyString strResult(*this);
	strResult.Append(pszParam);
	return strResult;
}

//전역함수
CMyString operator + (const char *pszLeft, const CMyString & strRight)
{
	CMyString strResult(pszLeft);
	strResult.Append(strRight.m_pszData);
	return strResult;
}

int CMyString::TestFunc(const char* pszParam)
{
	return SetString(pszParam);
}

int CMyString::OnSetString(const char *pszParam)
{
	return 1;
}
