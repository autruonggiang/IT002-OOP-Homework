#pragma once

#include <iostream>
using namespace std;

class DaThuc
{
private:
	int n;
	float* HeSo;
public:
	DaThuc();
	~DaThuc() {};

	//void Input();
	//void Output();
	/*void Tang();
	void Giam();*/

	friend istream& operator>>(istream& is, DaThuc& p);
	friend ostream& operator<<(ostream& os, DaThuc p);

	DaThuc& operator=(const DaThuc& dt);
	friend DaThuc operator+(const DaThuc dt1, const DaThuc dt2);
	friend DaThuc operator-(const DaThuc dt1, const DaThuc dt2);
	friend DaThuc operator*(const DaThuc dt1, const DaThuc dt2);
	friend DaThuc operator/(const DaThuc dt1, const DaThuc dt2);

	float& operator[](int i);
	DaThuc& operator++();
	DaThuc operator++(int);
	DaThuc& operator--();
	DaThuc operator--(int);

	float Value(float x);


};