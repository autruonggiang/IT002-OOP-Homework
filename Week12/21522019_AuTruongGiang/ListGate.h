#pragma once
#include "Gate.h"
#include "AcademicGate.h"
#include "BusinessGate.h"
#include "PowerGate.h"

using namespace std;

class ListGate
{
	int SoLuong;
	vector <Gate*> List;
public:
	void Nhap();
	bool Rescue(Prince&);
	int getSoLuong();
	void CheckRescue(Prince& P);
};