#pragma once
#include <iostream>

using namespace std;

class Prince
{
	int Money;
	int IQ;
	int Power;
public:
	void Nhap();
	void Xuat();
	int getMoney();
	void setMoney(int);
	int getIQ();
	int getPower();
	void setPower(int);
};