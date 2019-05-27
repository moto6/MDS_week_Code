#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// 그'들'
	int *pA, *pB;

	// 한 친구의 그녀 탄생
	pA = new int;
	*pA = 10;

	// 자기 여자 친구 놔두고 친구의 친구를 마음에 담은 바보
	pB = new int;
	pB = pA;

	// 그렇게 모두 잘 지내는 것처럼 보인다.
	cout << *pA << endl;
	cout << *pB << endl;

	// 그럼 이건?
	delete pA;
	delete pB;

	return 0;
}