#include "NVQuanLy.h"

NVQL::NVQL(string Na, Date bDay, int Basic, float Coe, int Gift) :NhanVien(Na, bDay, Basic)
{
	HeSoChucVu = Coe;
	Thuong = Gift;
}

void NVQL::Xuat()
{
	this->NhanVien::Xuat();
	cout << "He so chuc vu: " << HeSoChucVu << endl;
	cout << "Tien thuong: " << Thuong << endl;
	cout << "Luong: " << TinhLuong() << endl;
}

void NVQL::Nhap()
{
	this->NhanVien::Nhap();
	cout << "Nhap he so chuc vu: ";
	cin >> HeSoChucVu;
	cout << "Nhap so tien thuong: ";
	cin >> Thuong;
}

int NVQL::TinhLuong()
{
	return (this->GetLuongCanBan() * HeSoChucVu + Thuong);
}

NhanVien* NVQL::Clone()
{
	NhanVien* p = new NVQL(*this);
	return p;
}