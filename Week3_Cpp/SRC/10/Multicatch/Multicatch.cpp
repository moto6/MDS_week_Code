#include "stdafx.h"
#include <iostream>
using namespace std;

void ExceptTest1()
{
	int nInput;
	cout << "1~10 양의 정수를 입력하세요.: ";
	cin >> nInput;

	// 범위를 벗어난 숫자면 예외를 던진다.
	if (nInput < 1 || nInput > 10)
		throw nInput;
}

void ExceptTest2()
{
	char ch;
	cout << "Menu: [A]dd\t[D]elete\t[E]xit\n:";
	cin >> ch;

	// 없는 메뉴를 선택하면 예외를 던진다.
	if (ch != 'A' && ch != 'D' && ch != 'E')
		throw ch;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "*****Begin*****" << endl;
	try
	{
		// 정상적인 흐름이 한 블록 안에 모두 보인다.
		ExceptTest1();
		ExceptTest2();
	}

	// 예외 상황은 별도로 분류하고 상황에 따라 구별해서 볼 수 있다.
	catch (int nExp)
	{
		cout << "ERROR:" << nExp << "은(는) 범위를 벗어난 숫자입니다." << endl;
	}

	catch (char ch)
	{
		cout << "ERROR: " << ch << " 알 수 없는 메뉴입니다." << endl;
	}

	cout << "******End******" << endl;

	return 0;
}