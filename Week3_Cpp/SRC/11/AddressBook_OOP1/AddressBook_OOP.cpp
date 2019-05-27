#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList DB;
	CUserInterface UI(DB);
	UI.Run();

	return 0;
}