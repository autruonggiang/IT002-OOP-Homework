#include "TheThao.h"
#include <iostream>
#include "Nhom.h"

using namespace std;

void TheThao::Nhap()
{
	Nhom::Nhap();
	cout << "So mon the thao: ";
	cin >> SoMonTT;
	cout << "So danh hieu: ";
	cin >> SoDanhHieu;
	cout << "Ti le thang: ";
	cin >> TiLeThang;
}

void TheThao::Xuat()
{
	Nhom::Xuat();
	cout << "\nSo mon the thao: " << SoMonTT;
	cout << "\nSo danh hieu: " << SoDanhHieu;
	cout << "\nTi le thang: " << TiLeThang;
	if (XepLoai()) cout << "\nXep loai: Dat ";
	else cout << "\nXep loai: Khong dat ";
}

int TheThao::TinhDiem()
{
	return int((SoHD / TGHD) * 30 + (SoMonTT / static_cast<float>(15)) * 20 + (SoDanhHieu * static_cast<float>(2) / TGHD) * 30 + TiLeThang * 20);
}

bool TheThao::XepLoai()
{
	if (TinhDiem() >= 80 && TiLeThang >= 0.75) return true;
	return false;
}

bool TheThao::PhanLoai()
{
	return false;
}