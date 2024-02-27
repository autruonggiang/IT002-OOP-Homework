#include <iostream>
#include "BusinessGate.h"
#include "AcademicGate.h"
#include "PowerGate.h"

using namespace std;

int main()
{
    int n, type;
    int SoTien, TriTue, SucManh;
    Business_Gate C1;
    Academic_Gate C2;
    Power_Gate C3;
    cout << "\n==========Nhap chi so cua Hoang Tu===========\n";
    cout << "Nhap vao = > SO TIEN: "; cin >> SoTien;
    cout << "Nhap vao = > TRI TUE: "; cin >> TriTue;
    cout << "Nhap vao = > SUC MANH: "; cin >> SucManh;
    cout << "Chi so cua Hoang Tu la: [" << SoTien << "," << TriTue << "," << SucManh << "]";
    cout << "\nNhap so luong cong :";
    cin >> n;
    cout << "\n=====1.Cong Giao Thuong (Business_Gate) =====\n";
    cout << "\n======2.Cong Hoc Thuat (Academic_Gate) ======\n";
    cout << "\n========3.Cong Suc Manh (Power_Gate) ========\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap loai cong (1,2,3): ";
        cin >> type;
        if (type == 1)
        {
            C1.Nhap();
            SoTien -= C1.TraVe();
            if (SoTien < 0)
            {
                cout << "Hoang Tu da guc nga o cong: " << i + 1 << "\n";
                return 0;
            }
            else cout << "Hoang Tu da vuot qua thanh cong cong Giao Thuong (Business Gate) \n";
        }
        if (type == 2)
        {
            C2.Nhap();
            if (C2.TraVe() > TriTue)
            {
                cout << "Hoang Tu da guc nga o cong: " << i + 1 << "\n";
                return 0;
            }
            else cout << "Hoang Tu da vuot qua thanh cong cong Hoc Thuat (Academi Gate) \n";
        }
        if (type == 3)
        {
            C3.Nhap();
            SucManh -= C3.TraVe();
            if (SucManh < 0)
            {
                cout << "Hoang Tu da guc nga o cong: " << i + 1 << "\n";
                return 0;
            }
            else cout << "Hoang Tu da vuot qua thanh cong cong Suc Manh (Power Gate) \n";
        }
        cout << "Chi so cua Hoang Tu sau khi vuot qua cong thu " << i + 1 << " la: [" << SoTien << "," << TriTue << "," << SucManh << "]";
    }
    cout << "\n====================================================";
    cout << "\nHoang Tu da giai cuu thanh cong cong chua ";
    cout << "\nChi so cua Hoang Tu la: [" << SoTien << "," << TriTue << "," << SucManh << "]";
    cout << "\n====================================================\n";
}