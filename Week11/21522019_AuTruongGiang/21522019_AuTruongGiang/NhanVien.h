#pragma once

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class NhanVien
{
private:
	string Name;
	Date BirthDay;
	int LuongCanBan;
public:
	NhanVien(string Na = "", Date bDay = (1, 1, 1), int Basic = 0);
	string GetHoTen();
	Date GetBirthDay();
	int GetLuongCanBan();
	virtual void Nhap();
	virtual void Xuat();
	virtual int TinhLuong() = 0;
	virtual NhanVien* Clone() = 0;
};