#pragma once
#include<iostream>
using namespace std;
class SinhVien
{
private:
	string maso;
	string hoten;
	string diachi;
	int tongtinchi;
	float dtb;
public:
	SinhVien();
	void nhap();
	void xuat();
	int gettongtc()
	{
		return tongtinchi;
	}
	float getdtb()
	{
		return dtb;
	}
};
