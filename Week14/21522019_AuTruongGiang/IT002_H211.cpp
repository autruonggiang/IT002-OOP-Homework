#include "IT002_H211.h"
#include <iostream>

using namespace std;

void IT002_H211::Nhap()
{
	int Loai;
	cout << "Nhap so luong sinh vien: ";
	cin >> SoSV;
	cout << "Nhap so luong nhom: ";
	cin >> SoNhom;
	DSNhom = new Nhom * [SoNhom];
	for (int i = 0; i < SoNhom; i++)
	{
		cout << "Nhom can nhap:\n1-Hoc Tap\n2-Van Nghe\n3-The Thao\nVui long nhap so thich hop: ";
		cin >> Loai;
		switch (Loai)
		{
		case 1:
			DSNhom[i] = new HocTap;
			DSNhom[i]->Nhap();
			sum = sum + DSNhom[i]->TinhDiem();
			sumHT++;
			break;
		case 2:
			DSNhom[i] = new VanNghe;
			DSNhom[i]->Nhap();
			sum = sum + DSNhom[i]->TinhDiem();
			sumVN++;
			break;
		case 3:
			DSNhom[i] = new TheThao;
			DSNhom[i]->Nhap();
			sum = sum + DSNhom[i]->TinhDiem();
			sumTT++;
			break;
		default:
			cout << "Nhap sai! \n";
			cout << "Nhap lai: ";
			cin >> Loai;
			break;
		}
	}

}

void IT002_H211::Xuat()
{
	for (int i = 0; i < SoNhom; i++)
	{
		DSNhom[i]->Xuat();
	}
}

void IT002_H211::DongTV()
{
	int MAX = 0, NHOMMAX;
	for (int i = 0; i < SoNhom; i++)
	{
		if (DSNhom[i]->getSoTV() > MAX)
		{
			NHOMMAX = i;
			MAX = DSNhom[i]->getSoTV();
		}

	}
	cout << "\nNhom co dong thanh vien nhat la: ";
	DSNhom[NHOMMAX]->Xuat();
}

void IT002_H211::DiemDGcaoNhat()
{
	int MAX = 0, NHOMMAX;
	for (int i = 0; i < SoNhom; i++)
	{
		if (DSNhom[i]->TinhDiem() > MAX)
		{
			NHOMMAX = i;
			MAX = DSNhom[i]->TinhDiem();
		}

	}
	cout << "\nTen nhom co diem danh gia cao nhat la: " << DSNhom[NHOMMAX]->getTen();
}


void IT002_H211::HDVanNghe()
{
	int MAX = 0, NHOMMAX;
	for (int i = 0; i < SoNhom; i++)
	{
		if (DSNhom[i]->PhanLoai())
		{
			if (DSNhom[i]->getSoHD() > MAX)
			{
				NHOMMAX = i;
				MAX = DSNhom[i]->getSoHD();
			}
		}
	}
	cout << "\nTen nhom thuoc mang van nghe co nhieu hoat dong nhat la: " << DSNhom[NHOMMAX]->getTen();
}



void IT002_H211::HoatDongThamGiaNhieu()
{
	if (sumHT > sumTT && sumHT >> sumVN)
	{
		cout << "\nLoai hoat dong ->hoc tap<- co nhieu nhom tham gia nhat ";
	}
	if (sumTT > sumHT && sumTT >> sumVN)
	{
		cout << "\nLoai hoat dong ->the thao<- co nhieu nhom tham gia nhat ";
	}
	if (sumVN > sumTT && sumVN > sumHT)
	{
		cout << "\nLoai hoat dong ->van nghe<- co nhieu nhom tham gia nhat ";

	}
}

void IT002_H211::TongHD()
{
	cout << "\nHoat dong hoc tap co " << sumHT << " nhom ";
	cout << "\nHoat dong van nghe co " << sumVN << " nhom ";
	cout << "\nHoat dong the thao co " << sumTT << " nhom ";
	cout << "\nTong hoat dong cua lop la: " << sumHT + sumVN + sumTT;
}


bool IT002_H211::DanhGia()
{
	for (int i = 0; i < SoNhom; i++)
	{
		if (!DSNhom[i]->XepLoai()) dem++;
	}
	double s = dem / SoNhom;
	if (sumHT >= 1 && sumVN >= 1 && sumTT >= 1 && (sum / SoNhom) >= 80 && s <= 0.2)
		return true;
	return false;
}

void IT002_H211::LopIT()
{
	if (DanhGia()) cout << "\nTot";
	else cout << "\nKhong tot";
}