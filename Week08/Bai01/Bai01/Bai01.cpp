#include <iostream>
#include"DaThuc.h"

int main()
{
	DaThuc a, b;
	cin >> a;
	cin >> b;
	cout << "a: " << a;
	cout << "b: " << b;

	cout << "a + b = " << a + b << "\n";
	cout << "a - b = " << a - b << "\n";
	cout << "a * b = " << a * b << "\n";

	cout << "++a = " << ++a << "\n";
	cout << "--b = " << --b << "\n";

	return 0;
}