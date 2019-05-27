#include "stdafx.h"
#include <iostream>
using namespace std;

// 초기 제작자
#define DEFAULT_FARE 1000

class CPerson
{
public:
	CPerson() { }
	virtual ~CPerson() {
		cout << "virtual ~CPerson()" << endl;
	}

	// 요금 계산 인터페이스(순수 가상 함수)
	virtual void CalcFare() = 0;

	virtual unsigned int GetFare() { return m_nFare; }

protected:
	unsigned int m_nFare = 0;
};

// 초기 혹은 후기 제작자
class CBaby : public CPerson
{
public:
	// 영유아(0~7세) 요금 계산
	virtual void CalcFare()	 {
		m_nFare = 0;	  // 0%
	}
};

class CChild : public CPerson
{
public:
	// 어린이(8~13세) 요금 계산
	virtual void CalcFare()	 {
		m_nFare = DEFAULT_FARE * 50 / 100;	  // 50%
	}
};

class CTeen : public CPerson
{
public:
	// 청소년(14~19세) 요금 계산
	virtual void CalcFare()	 {
		m_nFare = DEFAULT_FARE * 75 / 100;	  // 75%
	}
};

class CAdult : public CPerson
{
public:
	// 성인(20세 이상) 요금 계산
	virtual void CalcFare()	 {
		m_nFare = DEFAULT_FARE;				  // 100%
	}
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv[])
{
	CPerson* arList[3] = { 0 };
	int nAge = 0;

	// 1. 자료 입력: 사용자 입력에 따라서 생성할 객체 선택
	for (auto &person : arList)
	{
		cout << "나이를 입력하세요: ";
		cin >> nAge;
		if (nAge < 8)
			person = new CBaby;

		else if (nAge < 14)
			person = new CChild;

		else if (nAge < 20)
			person = new CTeen;

		else
			person = new CAdult;

		// 생성한 객체에 맞는 요금이 자동으로 계산된다.
		person->CalcFare();
	}

	// 2. 자료 출력: 계산한 요금을 활용하는 부분
	for (auto person : arList)
		cout << person->GetFare() << "원" << endl;

	// 3. 자료 삭제 및 종료
	for (auto person : arList)
		delete person;

	return 0;
}