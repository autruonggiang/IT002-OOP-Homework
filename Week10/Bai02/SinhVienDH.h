#pragma once
#include"SinhVien.h"
class SinhVienDH:public SinhVien
{
private:
	string tenlv;
	float diemlv;
public:
	void nhap();
	void xuat();
	float getdiemlv()
	{
		return diemlv;
	}
};
