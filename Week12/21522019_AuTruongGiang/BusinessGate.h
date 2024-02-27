#pragma once
#include "Gate.h"

using namespace std;

class BusinessGate :public Gate
{
	int DonGia;
	int SoHang;
public:
	BusinessGate(int dg = 0, int sh = 0);
	void Nhap();
	void Xuat();
	int Tien();
	bool Pass(Prince&);
};