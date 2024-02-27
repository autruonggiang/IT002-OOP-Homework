#pragma once

#include "NhanVien.h"

class NVVP :public NhanVien
{
private:
	int SoNgay;
	int TroCap;
public:
	NVVP(string Na = "", Date bDay = (1, 1, 1), int Basic = 0, int Numb = 0, int Sub = 0);
	void Nhap();
	void Xuat();
	int TinhLuong();
	NhanVien* Clone();
};