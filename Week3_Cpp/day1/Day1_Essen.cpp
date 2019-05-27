/*
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
//


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
*/




/*
//#define page 46
// set here
//===========================================
#ifdef page==10
//===========================================
#include <iostream>
int main(int argc, char** argv) {
	std::cout << "Hello, world" << std::endl;
	return 0;
}
//===========================================
#endif
//===========================================



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
#ifdef page==44 // templete
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


//===========================================
#ifdef page==0 // templete
//===========================================
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	return 0;
}
===========================================
#endif
//===========================================

/**/
