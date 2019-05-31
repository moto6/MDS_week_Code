#pragma once

class CMyString
{
public:
	CMyString(void);
	explicit CMyString(const char* pszParam);
	CMyString(const CMyString & rhs);
	virtual ~CMyString(void);

	int SetString(const char * pszParam);
	const char* GetString(void) const { return m_pszData; }
	int GetLength(void) const
	{
		if(m_pszData == NULL && m_nLength)
			m_nLength = 0;
		return m_nLength;
	}
private:
	// 동적할당된 메모리의 주소가 저장될 멤버.
	char *m_pszData;
	mutable int m_nLength;

public:
	void Release(void);
	CMyString& operator =(const CMyString &strParam);
	CMyString& operator =(const char * pszParam);
	CMyString operator +(const CMyString & rhs);
	int Append(const char* pszParam);
	CMyString operator +(const char* pszParam);
	friend CMyString operator + (const char *, const CMyString &);

	operator const char * () const
	{
		return m_pszData;
	}

	int TestFunc(const char* pszParam);
	virtual int OnSetString(const char*);
};



