#pragma once
#include "Nhom.h"

class HocTap:public Nhom
{
private:
	int SoMonHoc, SoHB;
public:
	void Nhap();
	void Xuat();
	int TinhDiem();
	bool XepLoai();
	bool PhanLoai();
};
