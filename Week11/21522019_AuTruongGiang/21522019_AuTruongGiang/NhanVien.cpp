#include "NhanVien.h"

NhanVien::NhanVien(string Na, Date bDay, int Basic)
{
	Name = Na;
	LuongCanBan = Basic;
	if (bDay.CheckDate())
		BirthDay = bDay;
	else
		BirthDay = (1, 1, 1);
}

string NhanVien::GetHoTen()
{
	return Name;
}

Date NhanVien::GetBirthDay()
{
	return BirthDay;
}

int NhanVien::GetLuongCanBan()
{
	return LuongCanBan;
}

void NhanVien::Xuat()
{
	cout << "\nHo va ten: " << Name << endl;
	cout << "Ngay sinh: " << BirthDay;
	cout << "Luong can ban: " << LuongCanBan << endl;
}

void NhanVien::Nhap()
{
	cin.ignore();
	cout << "Ho va ten: ";
	getline(cin, Name);
	cout << "Ngay sinh:\n";
	cin >> BirthDay;
	cout << "Nhap luong can ban: ";
	cin >> LuongCanBan;
}