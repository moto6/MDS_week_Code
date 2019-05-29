#include <iostream>
#include <cstdio>

class CMyData
{
public:
	CMyData()
	{

	}
	~CMyData()
	{

	}
	int GetData() const
	{
		return m_nData;
	}
	int SetData(int nParam)
	{
		m_nData = nParam;
		return nParam;
	}
private:
	int m_nData;
};


int main(int argc, char ** argv)
{
	CMyData a;
	CMyData b(a);
	auto c(0);
	//a + b; //:Cannot do op btween class
	c = a.GetData() + b.GetData();
	return 0;
}



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


