#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{
		cout << "남은사과" << numOfApples << endl;
		cout << "판매수익" << myMoney << endl;

	}
};


class Buyer
{
private:
	int myMoney;
	int numOfApples;

public:
	Buyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}

	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;

	}

	void ShowBuyResult() const
	{
		cout << "현재잔액" << myMoney << endl;
		cout << "사과갯수" << numOfApples << endl;

	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	Buyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일판매자" << endl;
	seller.ShowSalesResult();

	cout << "과일구매자" << endl;
	buyer.ShowBuyResult();

}






/*
//172p
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		cout << "constructor called" << endl;
		num1 = n1;
		num2 = n2;
	}
	~SimpleClass(void)
	{
		cout << "destructor called" << endl;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}

};

int main(void)
{
	SimpleClass sc1();
	SimpleClass Mysc = sc1();
	Mysc.ShowData();
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);
	return sc;
}
*/