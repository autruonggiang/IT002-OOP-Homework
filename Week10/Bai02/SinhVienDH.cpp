#include "SinhVienDH.h"
#include<iostream>
#include<string>
using namespace std;
void SinhVienDH::nhap()
{
	SinhVien::nhap();
	cin.ignore();
	cout << "\nNhap ten luan van: ";
	getline(cin, tenlv);
	//cin.ignore();
	cout << "\nDiem luan van: ";
	cin >> diemlv;
	cout << endl;
}
void SinhVienDH::xuat()
{
	cout << endl;
	SinhVien::xuat();
	cout << "\nTen luan van: " << tenlv << endl;;
	cout << "\nDiem luan van: " << diemlv << endl;;
}