#include "DanhSach.h"

int main()
{
	DanhSach TongHop;
	cout << "[Nhap danh sach nhan vien:]\n";
	TongHop.Nhap();
	cout << "[Danh sach nhan vien:]\n";
	TongHop.Xuat();
	cout << "/////\n[Tong luong phai tra cua cong ty:] " << TongHop.TinhTongLuong() << endl;
	cout << "/////\n";
	TongHop.TimKiemTheoHoTen();
	return 0;
}