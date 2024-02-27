#include "DanhSach.h"

void DanhSach::Nhap()
{
	int SLQuanLy, SLVanPhong, SLSanXuat;
	cout << "Cong ty cua ban co bao nhieu nhan vien quan ly: ";
	cin >> SLQuanLy;
	cout << "Cong ty cua ban co bao nhieu nhan vien van phong: ";
	cin >> SLVanPhong;
	cout << "Cong ty cua ban co bao nhieu nhan vien san xuat: ";
	cin >> SLSanXuat;
	for (int i = 0; i < SLQuanLy; i++)
	{
		cout << "Nhap thong tin nhan vien quan ly thu " << i + 1 << ": " << endl;
		NhanVien* p = new NVQL;
		p->Nhap();
		List.push_back(p);
	}
	for (int j = 0; j < SLVanPhong; j++)
	{
		cout << "Nhap thong tin nhan vien van phong thu " << j + 1 << ": " << endl;
		NhanVien* p = new NVVP;
		p->Nhap();
		List.push_back(p);
	}
	for (int k = 0; k < SLSanXuat; k++)
	{
		cout << "Nhap thong tin nhan vien san xuat thu " << k + 1 << ": " << endl;
		NhanVien* p = new NVSX;
		p->Nhap();
		List.push_back(p);
	}
}

void DanhSach::Xuat()
{
	for (NhanVien* i : List)
		i->Xuat();
}

int DanhSach::TinhTongLuong()
{
	int s = 0;
	for (NhanVien* i : List)
		s = s + i->TinhLuong();
	return s;
}

void DanhSach::TimKiemTheoHoTen()
{
	string search = "";
	int ifelse = 0;
	cin.ignore();
	cout << "Nhap ho ten can tim: ";
	getline(cin, search);
	cout << "Thong tin nhan vien can tim:\n";
	for (NhanVien* i : List)
	{
		if (i->GetHoTen() == search)
		{
			i->Xuat();
			ifelse = 1;
		}
	}
	if (ifelse == 0)
		cout << "Khong tim thay nhan vien tuong ung !\n";
}