#include "Gate.h"

using namespace std;

Gate::Gate(string name)
{
	Name = name;
}

void Gate::Xuat()
{
	cout << "Loai cong: " << Name;
}