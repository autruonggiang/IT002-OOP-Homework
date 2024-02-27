#pragma once
#include "Gate.h"

using namespace std;

class AcademicGate :public Gate
{
	int IQ;
public:
	AcademicGate(int iq = 0);
	void Nhap();
	void Xuat();
	bool Pass(Prince&);
};