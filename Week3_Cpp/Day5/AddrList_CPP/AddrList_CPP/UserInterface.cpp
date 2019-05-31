#include "StdAfx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"

CUserInterface::CUserInterface(CMyList &rList)
: m_List(rList)
{
}

CUserInterface::~CUserInterface(void)
{
}

void CUserInterface::Add(void)
{
	char szName[32] = {0};
	char szPhone[32] = {0};

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	printf("Input phone number : ");
	fflush(stdin);
	gets_s(szPhone, sizeof(szPhone));

	int nResult = m_List.AddNewNode( new CUserData(szName, szPhone) );
	if(nResult == 0)
	{
		puts("ERROR: 이미 존재하는 데이터입니다.");
		_getch();
	}
	else if(nResult == -1)
	{
		puts("ERROR: 욕설을 이름으로 쓸 수 없습니다.");
		_getch();
	}
}

void CUserInterface::Search(void)
{
	char szName[32] = {0};
	CUserData *pNode = NULL;

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName));

	pNode = static_cast<CUserData*>( m_List.FindNode(szName) );
	if(pNode != NULL)
	{
		pNode->PrintNode();
	}
	else
	{
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	}

	_getch();
}

void CUserInterface::Remove(void)
{
	char szName[32] = {0};

	printf("Input name : ");
	fflush(stdin);
	gets_s(szName, sizeof(szName) );

	m_List.RemoveNode(szName);
}

int CUserInterface::PrintUI(void)
{
	int nInput = 0;

	system("cls");
	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");

	scanf_s("%d", &nInput);
	return nInput;
}

int CUserInterface::Run(void)
{
	int nMenu = 0;
	while( (nMenu = PrintUI()) != 0 )
	{
		switch(nMenu)
		{
		case 1:		//Add
			Add();
			break;

		case 2:		//Search
			Search();
			break;

		case 3:		//Print all
			PrintAll();
			break;

		case 4:		//Remove
			Remove();
			break;
		}
	}

	return nMenu;
}

void CUserInterface::PrintAll(void)
{
	CMyIterator it = m_List.MakeIterator();
	CUserData *pNode = NULL;

	while( (pNode = static_cast<CUserData*>
		(it.GetCurrent()) ) != NULL)
	{
		pNode->PrintNode();
		it.MoveNext();
	}

	_getch();
}
