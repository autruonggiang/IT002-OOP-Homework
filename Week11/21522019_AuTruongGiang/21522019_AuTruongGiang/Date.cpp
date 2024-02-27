#include "Date.h"

Date::Date(int d, int m, int y)
{
	Day = d;
	Month = m;
	Year = y;
}

bool Date::CheckLeap()
{
	if (Year % 4 == 0 && Year % 100 != 0)
		return true;
	if (Year % 400 == 0)
		return true;
	return false;
}

bool Date::CheckDate()
{
	if (Day <= 0 || Month <= 0 || Month > 12 || Year <= 0)
		return false;
	switch (Month)
	{
	case 2:
		if (!this->CheckLeap())
			if (Day > 28)
				return false;
		if (Day > 29)
			return false;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (Day > 30)
			return false;
		break;
	default:
		if (Day > 31)
			return false;
		break;
	}
	return true;
}

int Date::TinhSoNgayDaQua()
{
	int SoNgay = Day;
	int t;
	for (int i = 1; i < Month; i++)
	{
		switch (i)
		{
		case 2:
			if (this->CheckLeap())
				t = 29;
			else
				t = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			t = 30;
			break;
		default:
			t = 31;
			break;
		}
		SoNgay += t;
	}
	return SoNgay;
}

bool Date::TimNgaySomHon(Date other)
{
	if (Year < other.Year)
		return true;
	if (Year > other.Year)
		return false;
	if (this->TinhSoNgayDaQua() < other.TinhSoNgayDaQua())
		return true;
	return false;
}

int Date::TinhKhoangCach(Date other)
{
	if (this->TinhSoNgayDaQua() < other.TinhSoNgayDaQua())
		if (other.CheckLeap())
			return (366 - other.TinhSoNgayDaQua() + this->TinhSoNgayDaQua());
		else
			return (365 - other.TinhSoNgayDaQua() + this->TinhSoNgayDaQua());
	if (this->TinhSoNgayDaQua() > other.TinhSoNgayDaQua())
		return (this->TinhSoNgayDaQua() - other.TinhSoNgayDaQua());

}

ostream& operator<<(ostream& os, Date h)
{
	os << h.Day << "/" << h.Month << "/" << h.Year << endl;
	return os;
}

istream& operator>>(istream& is, Date& h)
{
	cout << "Nhap ngay thang nam (cach nhau bang dau cach): ";
	do
	{
		is >> h.Day >> h.Month >> h.Year;
		if (!h.CheckDate())
			cout << "Vui long nhap lai: ";
	} while (!h.CheckDate());
	return is;
}