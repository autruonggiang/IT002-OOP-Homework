#include "ListGate.h"

using namespace std;

void ListGate::Nhap()
{
	SoLuong = 0;
	cout << "\nNhap so luong cong: ";
	cin >> SoLuong;
	cout << "1. Business Gate\n2. Academic Gate\n3. Power Gate\n";
	for (int i = 1; i <= SoLuong; i++)
	{
		int choice = 0;
		cout << "Cong thu " << i << " la: ";
		do
		{
			cin >> choice;
		} while (choice < 1 && choice >= 4);
		switch (choice)
		{
		case 1:
		{
			Gate* a = new BusinessGate;
			a->Nhap();
			List.push_back(a);
			cout << endl;
			break;
		}
		case 2:
		{
			Gate* b = new AcademicGate;
			b->Nhap();
			List.push_back(b);
			cout << endl;
			break;
		}
		case 3:
		{
			Gate* c = new PowerGate;
			c->Nhap();
			List.push_back(c);
			cout << endl;
			break;
		}
		}
	}
}

int ListGate::getSoLuong()
{
	return SoLuong;
}

bool ListGate::Rescue(Prince& P)
{
	cout << "GIAI CUU CONG CHUA!!";
	for (int j = 0; j < List.size(); j++)
	{
		//		for (Gate* i : List)
		{
			if (!(List[j]->Pass(P)))
			{
				cout << "\n\nHoang tu da dung tai cong " << j + 1 << endl;
				return false;
			}
			else
			{
				cout << "\n\nHoang tu vuot qua cong thu " << j + 1;
				cout << "\nChi so cua Hoang tu con lai: ";
				P.Xuat();
			}
		}
	}
	return true;
}

void ListGate::CheckRescue(Prince& P)
{
	if (Rescue(P))
	{
		cout << "\n\nHoang tu da cuu duoc cong chua!\n\n";
		cout << "Chi so con lai:\n";
		P.Xuat();
	}
	else
		cout << "\n>>Hoang tu giai cuu cong chua that bai...\n";
}