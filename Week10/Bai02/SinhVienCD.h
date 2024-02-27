#pragma once
#include"SinhVien.h"
class SinhVienCD:public SinhVien
{
private:
	float diemthiTN;
public:
	void nhap();
	void xuat();
	float getdiemTN()
	{
		return diemthiTN;
	}
};
