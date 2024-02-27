#pragma once
#include "Nhom.h"
#include "TheThao.h"
#include "VanNghe.h"
#include "HocTap.h"
#include <string>
using namespace std;

class IT002_H211
{
private:
	int SoSV, SoNhom;
	int sumHT = 0, sumVN = 0, sumTT = 0;
	int sum = 0, dem = 0;
	Nhom** DSNhom;
public:
	void Nhap();
	void Xuat();
	void DongTV();
	void DiemDGcaoNhat();
	void HoatDongThamGiaNhieu();
	void TongHD();
	void HDVanNghe();
	bool DanhGia();
	void LopIT();
};
