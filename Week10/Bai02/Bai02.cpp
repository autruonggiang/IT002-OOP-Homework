#include <iostream>
#include"SinhVienDH.h"
#include"SinhVienCD.h"
using namespace std;
int main()
{
    cout << "\nNhap so luong sinh vien dai hoc: ";
    int svdh;
    cin >> svdh;
    SinhVienDH* listDH;
    listDH = new SinhVienDH[svdh];
    for (int i = 0; i < svdh; i++)
    {
        listDH[i].nhap();
    }
    for (int i = 0; i < svdh; i++)
    {
        listDH[i].xuat();
    }
    cout << "\nNhap so luong sinh vien cao dang: ";
    int svcd;
    cin >> svcd;
    SinhVienCD* listCD;
    listCD = new SinhVienCD[svcd];
    for (int i = 0; i < svcd; i++)
    {
        listCD[i].nhap();
    }
    for (int i = 0; i < svcd; i++)
    {
        listCD[i].xuat();
    }
    int a = 0;
    for (int i = 0; i < svdh; i++)
    {
        if (listDH[i].gettongtc() >= 170 && listDH[i].getdtb() >= 5 && listDH[i].getdiemlv() >= 5)
        {
            a++;
        }
    }
    int b = 0;
    for (int i = 0; i < svcd; i++)
    {
        if (listCD[i].gettongtc() >= 120 && listCD[i].getdtb() >= 5 && listCD[i].getdiemTN() >= 5)
        {
            b++;
        }
    }
    cout << "\n[SO SINH VIEN TOT NGHIEP] " << a + b << endl;
    float maxdh = listDH[0].getdtb();
    int c = 0;
    for (int i = 0; i < svdh; i++)
    {
        if (maxdh < listDH[i].getdtb())
        {
            maxdh = listDH[i].getdtb();
            c = i;
        }
    }
    float maxcd = listCD[0].getdtb();
    int d = 0;
    for (int i = 0; i < svcd; i++)
    {
        if (maxcd < listCD[i].getdtb())
        {
            maxcd = listDH[i].getdtb();
            d = i;
        }
    }


    cout << "\n[SINH VIEN CO DIEM TRUNG BINH CAO NHAT]" << endl;
    if (maxdh > maxcd)
    {
        listDH[c].xuat();
    }
    else
    {
        listCD[d].xuat();
    }
}
