#pragma once
#include <iostream>

using namespace std;

class Power_Gate
{
private:
	int SucManh;
public:

	void Nhap()
	{
		cout << "Nhap vao SUC MANH =>: "; cin >> SucManh;
	}
	int TraVe()
	{
		return SucManh;
	}
};
