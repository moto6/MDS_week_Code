#include "stdafx.h"

// std::function 객체를 사용하기 위한 헤더 추가
#include <functional>

#include <iostream>
using namespace std;

// std::function 템플릿 클래스를 매개변수로 받는다.
void TestFunc(char* pszParam, std::function<int(char*, int)> param)
{
	cout << pszParam << endl;
	param("Hello", 10);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	::TestFunc(
		"TestFunc()",

		// 함수의 실인수로 함수 몸체를 람다식으로 기술한다.
		[](char *pszParam, int nParam)->int
		{
			cout << pszParam << " : " << nParam << endl;

			return 0;
		}
	);

	cout << "******End******" << endl;

	return 0;
}