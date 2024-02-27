#pragma once
#include "Nhom.h"

class VanNghe:public Nhom
{
private:
	int SoTheLoai, SoGiaiThuong;
public:
	void Nhap();
	void Xuat();
	int TinhDiem();
	bool XepLoai();
	bool PhanLoai();
};
