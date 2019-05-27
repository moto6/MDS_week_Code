







/*
//90p
#include <iostream>
using namespace std;
int nData = 100;

namespace TEST
{
	int nData = 200;

}

using namespace TEST

int main(int argc, char * *argv)
{
	cout << nData << endl;
	return 0;
}
*/





/*
//87p
using namespace std;

int nData = 200;
namespace TEST
{
	int nData = 100;
	void TestFunc(void)
	{
		cout << nData << endl;
	}

 }

int main(void)
{
	TEST::TestFunc();
	return 0;
}
*/






/*
//
namespace TEST
{
	int g_nData = 100;
	void TestFunc(void)
	{
		std::cout << "TEST::TestFunc()" << std::endl;

	}
}

int main(void)
{
	TEST::TestFunc();
	std::cout << TEST::g_nData << std::endl;

	return 0;

}
*/



/*
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//69p 에러발생
template <typename T>

T TestFunc(t a)
{
	std::cout << "parameter a : " << a << std::endl;

	return a;
}

int main(int argc, char **argv)
{
	std::cout << "int \t" << TestFunc(3) << std::endl;
	std::cout << "double \t" << TestFunc(3.3) << std::endl;
	std::cout << "char \t" << TestFunc('A') << std::endl;
	std::cout << "char* \t" << TestFunc("TestString") << std::endl;
	return 0;
}
*/



/*
//52p
using namespace std;
int main(void)
{
	int aList[5] = {10,20,30,40,50};
	
	for (int i = 0; i < 5; i++) {
		cout << aList[i] << ' ';
	}
	cout << endl;

	for (auto n : aList)
		cout << n << ' ';
	cout << endl;
	

	return 0;
}
*/



/*
//50p
using namespace std;

int TestFunc(int nParam)
{
	int nResult = nParam * 2;

	return nResult;
}

int main(void)
{
	int nInput = 0;

	cout << "Input number :";
	cin >> nInput;


	int &&rdata = nInput + 5;
	cout << rdata << endl;

	int &&result = TestFunc(10);
	result += 10;
	cout << result << endl;

	return 0;
	
}

*/

/*
//49p
using namespace std;

void Swap(int &a, int &b)
{
	int nTmp = a;
	a = b;
	b = nTmp;
}

int main(int argc, char ** argv)
{
	int x = 10, y = 20;
	Swap(x, y);
	cout << "x : " << x << endl;
	cout << "y : " << y << endl;

	return 0;
}
*/







/*
// wh
using namespace std;
int main(int argc, char** argv)
{
	int nData= 10;
	int &ref = nData;
	ref = 20;
	cout << nData << endl;

	//Like as pointer
	int *pnData =  &nData;
	*pnData = 30;
	cout << nData << endl;
	return 0;
}
*/




/*
//===========================================
#ifdef page == 48
//===========================================
#include <iostream>
using namespace std;
void TestFunc(int &rParam)
{
rParam=100;
}

int main(int argc, char** argv)
{
int nData= 0;
TestFunc(nData);
cout << nData << endl;
return 0;
}
//===========================================
#endif
//===========================================




//===========================================
#ifdef page==46
//===========================================
#include <iostream>//46p
using namespace std;

int main(int argc, char** argv)
{
int nData= 10;
int &ref = nData;
ref = 20;
cout << nData << endl;

//Like as pointer

int *pnData =  &nData;
*pnData = 30;
cout << nData << endl;


return 0;
}
//===========================================
#endif
//===========================================


//===========================================
#ifdef page==44
//===========================================
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
int *arr = new int[5];
for(int i=0; i<5 ; i++)
arr[i] = i+1 *10;
for(int i=0;i<5;i++)
cout << arr[i] << endl;

delete[] arr;

return 0;
}
//===========================================
#endif
//===========================================
*/





/*
//===========================================
#ifdef page==0 // templete
//===========================================
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	return 0;
}
== == == == == == == == == == == == == == == == == == == == == =
#endif
//===========================================

*/





/*test
int main()
{
	cout << "Hello world!" << endl;

	return 0;

}
*/

/*test
#include <iostream>
using namespace std;
int main(int argc, char ** argv)
{
cout << "Hello world!" << endl;
cout << "Hello world!" << endl;
cout << "Hello world!" << endl;
cout << "Hello world!" << endl;
cout << "Hello world!" << endl;
cout << "Hello world!" << endl;
return 0;
}
*///

