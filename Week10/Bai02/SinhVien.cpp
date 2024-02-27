#include "SinhVien.h"
#include<iostream>
#include<string>
using namespace std;
SinhVien::SinhVien()
{
	maso = "0";
	hoten = "0";
	diachi = "0";
	tongtinchi = 0;
	dtb = 0;
}
void SinhVien::nhap()
{
	//cin.ignore();
	cout << "\nNhap ma so sinh vien: ";
	cin.ignore();
	getline(cin, maso);
	cout << "\nNhap ho va ten sinh vien: ";
	getline(cin, hoten);
	cout << "\nNhap dia chi: ";
	getline(cin, diachi);
	cout << "\nNhap tong so tin chi: ";
	cin >> tongtinchi;
	cout << "\nNhap diem trung binh: ";
	cin >> dtb;

}
void SinhVien::xuat()
{
	cout << "\nHo ten: " << hoten << endl;
	cout << "\nMSSV: " << maso << endl;;
	cout << "\nDia chi: " << diachi << endl;
	cout << "\nTong tin chi: " << tongtinchi << endl;
	cout << "\nDiem trung binh: " << dtb << endl;
}