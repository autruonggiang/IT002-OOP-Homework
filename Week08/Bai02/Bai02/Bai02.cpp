#include"ThoiGian.h"
int main()
{
	ThoiDiem a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << a.Convert_to_Time(a.Convert_to_Sec()) << "\n";
	cout << b.Convert_to_Time(b.Convert_to_Sec()) << "\n";

	cout << "a + b = " << (a + b).Convert_to_Time((a + b).Convert_to_Sec()) << "\n";
	cout << "a - b = " << (a - b).Convert_to_Time((a - b).Convert_to_Sec()) << "\n";

	cout << "++a: " << ++a << "\n";
	cout << "--b: " << --b;
	return 0;
}