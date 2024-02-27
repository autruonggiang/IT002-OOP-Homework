#pragma once
#include "NVVanPhong.h"
#include "NVSanXuat.h"
#include "NVQuanLy.h"
#include <vector>

using namespace std;

class DanhSach
{
private:
	vector<NhanVien*>List;
public:
	void Nhap();
	void Xuat();
	int TinhTongLuong();
	void TimKiemTheoHoTen();
};