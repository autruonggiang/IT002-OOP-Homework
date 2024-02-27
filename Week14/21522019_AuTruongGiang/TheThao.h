#pragma once
#include "Nhom.h"

class TheThao:public Nhom
{
private:
	int SoMonTT, SoDanhHieu;
	float TiLeThang;
public:
	void Nhap();
	void Xuat();
	int TinhDiem();
	bool XepLoai();
	bool PhanLoai();
};
