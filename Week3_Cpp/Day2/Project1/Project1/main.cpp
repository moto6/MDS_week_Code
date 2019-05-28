#include <iostream>
#include <cstdio>
///*
//108p
using namespace std;

class CTest
{
public:
	CTest()
	{
		m_nData = 10;
	}

	int m_nData;
	void PrintData(void)
	{
		cout << m_nData << endl;

	}
};

int main(int argc, char * *argv)
{
	CTest t;
	t.PrintData();
	return 0;
}

//*/





/*
//106p
class USERDATA
{
public:
	int nAge;
	char szName[32];

	void Printf(void)
	{
		printf("%d %s\n", nAge, szName);
	}
};

int main(void)
{
	USERDATA user = { 10,"철수" };
	user.Printf();

	return 0;
}
*/







/*
//164p
using namespace std;
void TestFunc(const int &nParam)
{
int &nNewParam = const_cast<int &>(nParam)

}

*/






/*
//163p
using namespace std;
class CTest
{
public :
CTest(int nParam) : m_nData(nParam);
cTest(){}

int GetData() const
{
m_nData = 20;
return m_nData;
int Setdata(int nParam) { m_nData = nParam; }

private:
mutable int m_nData = 0;
}
}

int main(int argc, char ** argv)
{
CTest a(10);
cout << a.GetData << endl;

return 0;
}
*/








/*
//130p
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) {};
	CMyData(int x, int y) : m_nData(x + y) {};
	int GetData(void) { return m_nData; }

private:
	int m_nData;
};
int main(void)
{
	CMyData a(10);
	CMyData b(3, 4);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;

	return 0;
}
*/



/*
//128p
using namespace std;

class CRefTest
{
public :
	CRefTest(int &rParam) : m_nData(rParam) {};
	int GetData(void) { return m_nData; }

private:
	int &m_nData;
};
int main(int num, char* *string)
{
	int a = 10;
	CRefTest t(a);
	cout << t.GetData() << endl;

	a = 20;
	cout << t.GetData() << endl;


	return 0;
}
*/






/*
//126p
using namespace std;

class CTest
{
	int m_nData;
	
public:
	CTest()
	{
		cout << "CTest::Ctest()" << endl;
	}
	~CTest()
	{
		cout << "~CTest::Ctest()" << endl;

	}
};

int main(int argc, char * *argv)
{
	cout << "Begin" << endl;
	CTest *pData = new CTest;
	cout << "Test" << endl;

	delete pData;
	cout << "End" << endl;

	return 0;
}
*/




/*
//90p
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

