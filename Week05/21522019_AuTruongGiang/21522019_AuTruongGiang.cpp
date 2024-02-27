#include <iostream>
#include "PhanSo.h"
#include "DaThuc.h"

using namespace std;


void CalcPS(PS& a, PS& b) {
    PS c = a + b;
    cout << "Tong hai phan so (a + b) = " << c << endl;

    c = a - b;
    cout << "Hieu hai phan so (a - b) = " << c << endl;

    c = a * b;
    cout << "Tich hai phan so (a * b) = " << c << endl;

    c = a / b;
    cout << "Thuong hai phan so (a / b) = " << c << endl;

    int num;
    cout << "\nNhap so nguyen bat ky: ";
    cin >> num;

    c = a + num;
    cout << "a + " << num << " = " << c << endl;

    c = a - num;
    cout << "a - " << num << " = " << c << endl;

    c = a * num;
    cout << "a * " << num << " = " << c << endl;

    c = a / num;
    cout << "a / " << num << " = " << c << endl;
}

void solvePS() {
    cout << "[Nhap, xuat phan so]" << endl;
    PS a, b;
    cout << "Phan so thu nhat\n";
    cin >> a;
    cout << "\nPhan so thu hai\n";
    cin >> b;

    cout << "_________________________\n";
    cout << "Phan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;

    cout << endl;
    cout << "[Tinh toan 2 phan so]" << endl;
    CalcPS(a, b);
}

void solveDT() {
    DaThuc a, b;

    cout << "Nhap da thuc thu 1: " << endl;
    cin >> a;
    cout << "a = " << a;

    int num;
    cout << "Gia tri cua x: ";
    cin >> num;
    cout << "a(" << num << ") = " << a.calcDT(num) << endl << endl;

    cout << "Nhap da thuc thu 2: " << endl;
    cin >> b;
    cout << "b = " << b << endl;

    cout << "a = ";
    cout << a;

    cout << "b = ";
    cout << b;

    cout << endl;

    DaThuc c;

    c = a + b;
    cout << "Tong hai da thuc (a + b) = " << c;

    c = a - b;
    cout << "Hieu hai da thuc (a - b) = " << c << endl;

    c = a * b;
    cout << "Tich hai da thuc (a * b) = " << c;

    cout << "\nNhap gia tri nguyen bat ky: ";
    cin >> num;

    c = a + num;
    cout << "a + " << num << " = " << c;

    c = a - num;
    cout << "a - " << num << " = " << c;

    c = a * num;
    cout << "a * " << num << " = " << c;

}

int main() {

    solvePS();
    solveDT();

    return 0;
}