#include "SinhVienCD.h"
#include<iostream>
using namespace std;
void SinhVienCD::nhap()
{
	SinhVien::nhap();
	cout << "\nNhap diem thi tot nghiep: ";
	cin >> diemthiTN;
}
void SinhVienCD::xuat()
{
	cout << endl;
	SinhVien::xuat();
	cout << "\nDiem thi tot nghiep: " << diemthiTN;
}