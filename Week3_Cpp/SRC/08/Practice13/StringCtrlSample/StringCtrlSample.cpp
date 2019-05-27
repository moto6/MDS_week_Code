#include "stdafx.h"
#include "MyStringEx.h"

int _tmain(int argc, _TCHAR* argv[]) {
	CMyString b("World"), c;
	c = "Hello" + b;
	cout << c << endl;

	return 0;
}