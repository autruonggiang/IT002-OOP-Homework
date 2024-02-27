#include <iostream>
#include "Prince.h"
#include "Gate.h"
#include "ListGate.h"

int main()
{
    Prince VD;
    cout << "Nhap thong tin cua Hoang tu\n";
    VD.Nhap();
    ListGate Castle;
    cout << "\nNhap thong tin cua cac cong:";
    Castle.Nhap();
    Castle.CheckRescue(VD);
    return 0;
}