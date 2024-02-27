#pragma once

#include "NhanVien.h"

class NVSX :public NhanVien
{
	int SoSanPham;
public:
	NVSX(string Na = "", Date bDay = (1, 1, 1), int Basic = 0, int NumbPrd = 0);
	void Nhap();
	void Xuat();
	int TinhLuong();
	NhanVien* Clone();
};