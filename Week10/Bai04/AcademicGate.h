#pragma once
#include <iostream>

using namespace std;

class Academic_Gate
{
private:
	int TriTue;
public:
	void Nhap()
	{
		cout << "Nhap vao TRI TUE =>: "; cin >> TriTue;
	}
	int TraVe()
	{
		return TriTue;
	}
};
