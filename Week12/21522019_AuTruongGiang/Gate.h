#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Prince.h"

using namespace std;

class Gate
{
	string Name;
public:
	Gate(string name = NULL);
	virtual void Nhap() = 0;
	virtual void Xuat();
	virtual bool Pass(Prince&) = 0;
};