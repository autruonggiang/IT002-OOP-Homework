#include "PowerGate.h"

using namespace std;

PowerGate::PowerGate(int p) : Gate("Power Gate")
{
	Power = p;
}

void PowerGate::Nhap()
{
	cout << "Nhap chi suc manh cua dung si: ";
	cin >> Power;
}

void PowerGate::Xuat()
{
	cout << "Chi so suc manh: " << Power;
}

bool PowerGate::Pass(Prince& P)
{
	if (P.getPower() < Power)
		return false;
	P.setPower(P.getPower() - Power);
	return true;
}
