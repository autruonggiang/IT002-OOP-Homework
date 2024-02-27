#include "BusinessGate.h"

using namespace std;

BusinessGate::BusinessGate(int dg, int sh) : Gate("Business Gate")
{
	DonGia = dg;
	SoHang = sh;
}

void BusinessGate::Nhap()
{
	cout << "Nhap don gia: ";
	cin >> DonGia;
	cout << "Nhap so hang: ";
	cin >> SoHang;
}

void BusinessGate::Xuat()
{
	cout << "Don gia: " << DonGia;
	cout << "So hang: " << SoHang;
}

int BusinessGate::Tien()
{
	return DonGia * SoHang;
}

bool BusinessGate::Pass(Prince& P)
{
	if (P.getMoney() < Tien())
		return false;
	P.setMoney(P.getMoney() - Tien());
	return true;
}