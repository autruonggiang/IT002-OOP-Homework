#include"ThoiGian.h"

ThoiDiem::ThoiDiem()
{
	Hours = 0;
	Minutes = 0;
	Seconds = 0;
}
ThoiDiem::ThoiDiem(int h, int m, int s)
{
	while (s >= 60)
	{
		m = m + s / 60;
		s = s % 60;
		while (m >= 60)
		{
			h = h + m / 60;
			m = m % 60;
		}
	}
	Hours = h;
	Minutes = m;
	Seconds = s;
}

ThoiDiem::~ThoiDiem() {}

int ThoiDiem::Convert_to_Sec()
{
	return Hours * 3600 + Minutes * 60 + Seconds;
}
ThoiDiem ThoiDiem::Convert_to_Time(int time)
{
	ThoiDiem Temp;
	Temp.Hours = time / 3600;
	time = time % 3600;
	Temp.Minutes = time / 60;
	time = time % 60;
	Temp.Seconds = time;
	return Temp;
}

ThoiDiem& ThoiDiem::operator=(const ThoiDiem& dt)
{
	Hours = dt.Hours;
	Minutes = dt.Minutes;
	Seconds = dt.Seconds;
	return *this;
}

ThoiDiem operator+(ThoiDiem td1, ThoiDiem td2)
{
	ThoiDiem Temp;
	int iTemp = td1.Convert_to_Sec() + td2.Convert_to_Sec();
	return Temp.Convert_to_Time(iTemp);
}
ThoiDiem operator-(ThoiDiem td1, ThoiDiem td2)
{
	ThoiDiem Temp;
	int iTemp = td1.Convert_to_Sec() - td2.Convert_to_Sec();
	Temp = Temp.Convert_to_Time(iTemp);
	return Temp;
}

istream& operator>>(istream& is, ThoiDiem& dt)
{
	cout << "Nhap thoi gian: ";
	cin >> dt.Hours >> dt.Minutes >> dt.Seconds;
	return is;
}
ostream& operator<<(ostream& os, ThoiDiem dt)
{
	if (dt.Convert_to_Sec() < 0) cout << "[ERROR] 00:00:00 ";
	else
	{
		cout << dt.Hours << ":";
		if (dt.Minutes < 10)
			cout << "0" << dt.Minutes << ":";
		else
			cout << dt.Minutes << ":";
		if (dt.Seconds < 10)
			cout << "0" << dt.Seconds << " ";
		else
			cout << dt.Seconds << " ";
	}
	return os;
}
ThoiDiem& ThoiDiem::operator++() {
	++Seconds;
	return *this;
}
ThoiDiem ThoiDiem::operator++(int) {
	ThoiDiem t = *this;
	++Seconds;
	return t;
}
ThoiDiem& ThoiDiem::operator--() {
	--Seconds;
	return *this;
}
ThoiDiem ThoiDiem::operator--(int) {
	ThoiDiem t = *this;
	--Seconds;
	return t;
}