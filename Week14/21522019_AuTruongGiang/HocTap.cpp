#include "HocTap.h"
#include "Nhom.h"
#include <iostream>

using namespace std;

void HocTap::Nhap()
{
	Nhom::Nhap();
	cout << "Nhap so mon: ";
	cin >> SoMonHoc;
	cout << "Nhap so hoc bong: ";
	cin >> SoHB;
}

void HocTap::Xuat()
{
	Nhom::Xuat();
	cout << "\nSo mon: " << SoMonHoc;
	cout << "\nSo hoc bong: " << SoHB;
	if (XepLoai()) cout << "\nXep loai: Dat ";
	else cout << "\nXep loai: Khong dat ";
}

int HocTap::TinhDiem()
{
	return int((SoHD / TGHD) * 30 + (SoMonHoc / 10) * 50 + (SoHB / SoTV) * 20);
}

bool HocTap::XepLoai()
{
	if (TinhDiem() >= 80 && (SoHB / SoTV) >= 0.5) return true;
	return false;
}

bool HocTap::PhanLoai()
{
	return false;
}

