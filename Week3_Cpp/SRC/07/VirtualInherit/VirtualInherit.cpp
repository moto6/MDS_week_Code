#include "stdafx.h"
#include <iostream>
using namespace std;

class CMyObject
{
public:
	CMyObject() { cout << "CMyObject()" << endl; }
	virtual ~CMyObject() { }
};

class CMyImage : public CMyObject
{
public:
	CMyImage() { cout << "CMyImage(int, int)" << endl; }
};

class CMyShape : public CMyObject
{
public:
	CMyShape() { cout << "CMyShape(int)" << endl; }
};

class CMyPicture : public CMyImage, public CMyShape
{
public:
	CMyPicture() { cout << "CMyPicture()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyPicture a;
}