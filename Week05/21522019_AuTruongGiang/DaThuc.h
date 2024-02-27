#pragma once

#include <iostream>
#include <math.h>

using namespace std;

class DaThuc
{

	int bac;
	int* heSo;
	int x;

public:

	DaThuc(int x) {
		itoDT(x);
	}

	DaThuc() {
		itoDT(0);
	}

	void setBac(int bac) { this->bac = bac; }
	void setHeSo(int num) { this->heSo = new int[num]; }

	int* getHeSo() { return this->heSo; }
	int getBac() { return this->bac; }

	void itoDT(int a) {
		bac = 0;
		heSo = new int[1];
		heSo[0] = a;
	}

	void Input();

	void Output();

	int calcDT(int);

	friend void createEmpty(DaThuc& a) {
		for (int i = 0; i <= a.bac; ++i) {
			a.heSo[i] = 0;
		}
	}

	friend DaThuc sumDT(DaThuc, DaThuc);

	friend DaThuc subDT(DaThuc, DaThuc);

	friend DaThuc multiDT(DaThuc, DaThuc);

	friend DaThuc operator + (DaThuc a, DaThuc b) {
		return sumDT(a, b);
	}

	friend DaThuc operator - (DaThuc a, DaThuc b) {
		return subDT(a, b);
	}

	friend DaThuc operator * (DaThuc a, DaThuc b) {
		return multiDT(a, b);
	}

	friend ostream& operator << (ostream&, DaThuc&);
	friend istream& operator >> (istream&, DaThuc&);
};
