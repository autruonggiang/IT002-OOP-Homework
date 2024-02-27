#pragma once
#include<iostream>
using namespace std;

class ThoiDiem
{
private:
	int Hours, Minutes, Seconds;
public:
	ThoiDiem();
	ThoiDiem(int, int, int);
	~ThoiDiem();
	int Convert_to_Sec();
	ThoiDiem Convert_to_Time(int);

	ThoiDiem& operator=(const ThoiDiem&);

	friend ThoiDiem operator+(ThoiDiem, ThoiDiem);
	friend ThoiDiem operator-(ThoiDiem, ThoiDiem);

	friend istream& operator>>(istream&, ThoiDiem&);
	friend ostream& operator<<(ostream&, ThoiDiem);

	ThoiDiem& operator ++();
	ThoiDiem operator ++(int);
	ThoiDiem& operator --();
	ThoiDiem operator --(int);
};