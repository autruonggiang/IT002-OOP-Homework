#pragma once

#include <iostream>
#include <math.h>

using namespace std;

class Date
{
private:
	int Day;
	int Month;
	int Year;
public:
	Date(int d = 1, int m = 1, int y = 1);
	bool CheckLeap();
	bool CheckDate();
	int TinhSoNgayDaQua();
	bool TimNgaySomHon(Date other);
	int TinhKhoangCach(Date other);
	friend ostream& operator<<(ostream& os, Date h);
	friend istream& operator>>(istream& is, Date& h);
};