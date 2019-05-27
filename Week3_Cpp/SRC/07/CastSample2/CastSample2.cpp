#include "stdafx.h"
#include <iostream>
using namespace std;

class CShape
{
public:
	CShape() { }
	virtual ~CShape() { }
	virtual void Draw()	 { cout << "CShape::Draw()" << endl; }
};

class CRectangle : public CShape
{
public:
	virtual void Draw()	 { cout << "CRectangle::Draw()" << endl; }
};

class CCircle : public CShape
{
public:
	virtual void Draw()	 { cout << "CCircle::Draw()" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "도형 변호를 입력하세요. [1:사각형, 2:원]: " << endl;
	int nInput = 0;
	cin >> nInput;

	CShape *pShape = nullptr;
	if (nInput == 1)
		pShape = new CRectangle;

	else if (nInput == 2)
		pShape = new CCircle;

	else
		pShape = new CShape;

	// 좋은 예
	pShape->Draw();

	// '매우' 나쁜 예
	// 가상 함수를 활용한다면 이런 코드를 작성할 이유가 없다!
	CRectangle *pRect = dynamic_cast<CRectangle*>(pShape);
	if (pRect != NULL)
		cout << "CRectangle::Draw()" << endl;

	else
	{
		CCircle *pCricle = dynamic_cast<CCircle*>(pShape);
		if (pCricle != NULL)
			cout << "CCircle::Draw()" << endl;

		else
			cout << "CShape::Draw()" << endl;
	}

	return 0;
}