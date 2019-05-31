#pragma once

class CMyList;

class CUserInterface
{
public:
	CUserInterface(CMyList &rList);
	~CUserInterface(void);
	void Add(void);

protected:
	CMyList	&m_List;
public:
	void Search(void);
	void Remove(void);
	int PrintUI(void);
	int Run(void);
	void PrintAll(void);
};
