#pragma once
#include "Gate.h"

using namespace std;

class PowerGate :public Gate
{
	int Power;
public:
	PowerGate(int p = 0);
	void Nhap();
	void Xuat();
	bool Pass(Prince&);
};