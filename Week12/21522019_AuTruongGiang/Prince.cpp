#include "Prince.h"

using namespace std;

void Prince::Nhap()
{
	cout << "So tien cua Hoang tu: ";
	cin >> Money;
	cout << "Chi so IQ cua Hoang tu: ";
	cin >> IQ;
	cout << "Chi so suc manh cua Hoang tu: ";
	cin >> Power;
}

void Prince::Xuat()
{
	cout << "So tien cua Hoang tu hien tai: ";
	cout << Money;
	cout << "\nChi so IQ cua Hoang tu: ";
	cout << IQ;
	cout << "\nChi so suc manh cua Hoang tu hien tai: " << Power;
}

int Prince::getMoney()
{
	return Money;
}

int Prince::getIQ()
{
	return IQ;
}

void Prince::setMoney(int a)
{
	Money = a;
}

int Prince::getPower()
{
	return Power;
}

void Prince::setPower(int a)
{
	Power = a;
}