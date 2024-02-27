#include "Nhom.h"
#include <iostream>

using namespace std;

void Nhom::Nhap()
{
	cin.ignore();
	cout << "Nhap ten nhom: ";
	getline(cin, Ten);
	cout << "Nhap so luong thanh vien: ";
	cin >> SoTV;
	cout << "Nhap so luong cac hoat dong: ";
	cin >> SoHD;
	cout << "Nhap thoi gian hoat dong: ";
	cin >> TGHD;
}

void Nhom::Xuat()
{
	cout << "\nTen nhom: " << Ten;
	cout << "\nSo luong thanh vien: " << SoTV;
	cout << "\nSo luong cac hoat dong: " << SoHD;
	cout << "\nThoi gian hoat dong: " << TGHD;
}