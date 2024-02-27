#include "NVSanXuat.h"

NVSX::NVSX(string Na, Date bDay, int Basic, int NumbPrd) :NhanVien(Na, bDay, Basic)
{
	SoSanPham = NumbPrd;
}

void NVSX::Xuat()
{
	this->NhanVien::Xuat();
	cout << "So san pham: " << SoSanPham << endl;
	cout << "Luong: " << this->TinhLuong() << endl;
}

void NVSX::Nhap()
{
	this->NhanVien::Nhap();
	cout << "Nhap so san pham: ";
	cin >> SoSanPham;
}

int NVSX::TinhLuong()
{
	return (this->GetLuongCanBan() + SoSanPham * 2000);
}

NhanVien* NVSX::Clone()
{
	NhanVien* p = new NVSX(*this);
	return p;
}