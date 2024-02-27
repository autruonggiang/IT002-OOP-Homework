#pragma once
#include <string>
using namespace std;

class Nhom
{
protected:
	string Ten;
	int SoTV, SoHD, TGHD;

public:
	virtual void Nhap();
	virtual void Xuat();
	virtual int TinhDiem() = 0;
	virtual bool XepLoai() { return true; };
	int getSoTV() { return SoTV; }
	string getTen() { return Ten; }
	virtual bool PhanLoai() { return true; }
	int getSoHD() { return SoHD; }
};
