#include "VanNghe.h"
#include <iostream>
#include "Nhom.h"

using namespace std;

void VanNghe::Nhap()
{
	Nhom::Nhap();
	cout << "So the loai: ";
	cin >> SoTheLoai;
	cout << "So giai thuong: ";
	cin >> SoGiaiThuong;
}

void VanNghe::Xuat()
{
	Nhom::Xuat();
	cout << "\nThe loai: " << SoTheLoai;
	cout << "\nGiai thuong: " << SoGiaiThuong;
	if (XepLoai()) cout << "\nXep loai: Dat ";
	else cout << "\nXep loai: Khong dat ";
}

int VanNghe::TinhDiem()
{
	return int((SoHD / TGHD) * 30 + (SoTheLoai / 20) * 40 + (SoGiaiThuong * 3 / TGHD) * 30);
}

bool VanNghe::XepLoai()
{
	if (TinhDiem() >= 80 && (SoGiaiThuong >= (TGHD / 3))) return true;
	return false;
}

bool VanNghe::PhanLoai()
{
	return true;
}