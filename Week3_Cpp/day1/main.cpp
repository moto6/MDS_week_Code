//=================================================
//

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int aList[5] = {1,2,3,4,5};
	for(int i=0; i<5 ; ++i)
		cout << aList[i] <<' ';

	cout<<endl;
	for (auto &n: aList)
		cout << n << ' ';

	cout << endl;

	for(auto &n : aList)
		cout << n << ' ';
	cout << endl;




	return 0;
}
//=================================================
//





//=================================================
//
/*
#include <iostream>
using namespace std;

int nData(20);

int main(int argc, char ** argv)
{
    int nData(10);

    cout << nData << endl;
    cout << argc << endl;
    return 0;

}
*/