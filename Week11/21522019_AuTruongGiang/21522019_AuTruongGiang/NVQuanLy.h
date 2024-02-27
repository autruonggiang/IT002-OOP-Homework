#pragma once

#include "NhanVien.h"

class NVQL :public NhanVien
{
private:
	float HeSoChucVu;
	int Thuong;
public:
	NVQL(string Na = "", Date bDay = (1, 1, 1), int Basic = 0, float Coe = 0, int Gift = 0);
	void Nhap();
	void Xuat();
	int TinhLuong();
	NhanVien* Clone();
};