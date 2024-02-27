#pragma once
#include <iostream>

using namespace std;

class Business_Gate
{
protected:
	int DonGia, SoHang;
public:
	void Nhap()
	{
		cout << "Nhap vao DON GIA =>: "; cin >> DonGia;
		cout << "Nhap vao SO HANG =>: "; cin >> SoHang;
	}
	int TraVe()
	{
		return DonGia * SoHang;
	}
};
