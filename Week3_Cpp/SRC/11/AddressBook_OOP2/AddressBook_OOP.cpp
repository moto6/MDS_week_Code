#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList DB(new CUserData);
	CUserInterface UI(DB);
	UI.Run();

	return 0;
}