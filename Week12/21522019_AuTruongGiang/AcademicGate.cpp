#include "AcademicGate.h"

using namespace std;

AcademicGate::AcademicGate(int iq) : Gate("Academic Gate")
{
	IQ = iq;
}

void AcademicGate::Nhap()
{
	cout << "Nhap chi so tri tue cua cau hoi: ";
	cin >> IQ;
}

void AcademicGate::Xuat()
{
	cout << "Chi so tri tue: " << IQ;
}

bool AcademicGate::Pass(Prince& P)
{
	if (P.getIQ() < IQ)
		return false;
	return true;
}