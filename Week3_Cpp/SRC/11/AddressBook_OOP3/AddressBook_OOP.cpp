#include "stdafx.h"
#include "UserInterface.h"
#include "MyListEx.h"
#include "UserData.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyListEx DB(new CUserData("Dummy", "Head"));
	CUserInterface UI(DB);
	UI.Run();

	return 0;
}