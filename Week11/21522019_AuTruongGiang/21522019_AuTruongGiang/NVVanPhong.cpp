#include "NVVanPhong.h"

NVVP::NVVP(string Na, Date bDay, int Basic, int Numb, int Sub) :NhanVien(Na, bDay, Basic)
{
	SoNgay = Numb;
	TroCap = Sub;
}

void NVVP::Xuat()
{
	this->NhanVien::Xuat();
	cout << "So ngay lam viec: " << SoNgay << endl;
	cout << "Luong: " << TinhLuong() << endl;
}

void NVVP::Nhap()
{
	this->NhanVien::Nhap();
	cout << "Nhap so ngay lam viec: ";
	cin >> SoNgay;
}

int NVVP::TinhLuong()
{
	return (this->GetLuongCanBan() + SoNgay * 100000 + TroCap);
}

NhanVien* NVVP::Clone()
{
	NhanVien* p = new NVVP(*this);
	return p;
}