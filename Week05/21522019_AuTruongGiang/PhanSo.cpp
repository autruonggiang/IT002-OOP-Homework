#include "PhanSo.h"

long long int UCLN(long long int m, long long int n) {

    long long int num;
    m = (m < 0) ? -m : m;
    n = (n < 0) ? -n : n;

    if (m < n) {
        num = n;
        n = m;
        m = num;
    }

    if (n == 0 || m == n)
        return m;
    return UCLN(n, m % n);
}

void RutGon(PS&)
{
}

// For class PS
PS Minus(PS PS1, PS PS2) {
    PS new_PS;
    new_PS.mau = PS1.mau * PS2.mau;
    new_PS.tu = PS1.tu * PS2.mau - PS2.tu * PS1.mau;
    RutGon(new_PS);

    return new_PS;
}

PS Plus(PS PS1, PS PS2) {
    PS new_PS;
    new_PS.mau = PS1.mau * PS2.mau;
    new_PS.tu = PS1.tu * PS2.mau + PS2.tu * PS1.mau;

    RutGon(new_PS);

    return new_PS;
}

PS Multiply(PS PS1, PS PS2) {
    PS new_PS;
    long long int numTu = UCLN(PS1.tu, PS2.mau);
    long long int numMau = UCLN(PS1.mau, PS2.tu);

    new_PS.mau = PS1.mau / numMau * PS2.mau / numTu;
    new_PS.tu = PS1.tu / numTu * PS2.tu / numMau;

    RutGon(new_PS);

    return new_PS;
}

PS Devine(PS PS1, PS PS2) {
    PS new_PS;
    new_PS.mau = PS1.mau * PS2.tu;
    new_PS.tu = PS1.tu * PS2.mau;

    RutGon(new_PS);

    return new_PS;
}

bool CheckInt(float num) {
    int test = num;
    if (test == num)
        return true;

    return false;
}

void Input(PS& a) {

    float tu, mau;

    do {
        cout << "Nhap tu so: ";
        cin >> tu;

        if (!CheckInt(tu)) {
            cout << "Tu so phai la so nguyen !" << endl;
        }

    } while (!CheckInt(tu));

    do {
        cout << "Nhap mau so: ";
        cin >> mau;

        if (!CheckInt(mau)) {
            cout << "Mau so phai la so nguyen !" << endl;
        }
        else if (mau == 0) {
            cout << "Mau so phai khac 0 !" << endl;
        }

    } while (!CheckInt(mau) || mau == 0);

    a.tu = tu;
    a.mau = mau;
}

void Output(PS& a) {
    if (a.tu == 0)
        cout << "0";
    else if ((a.tu < 0 && a.mau < 0) || (a.tu > 0 && a.mau < 0))
        cout << -1 * a.tu << "/" << -1 * a.mau;
    else
        cout << a.tu << "/" << a.mau;
}


ostream& operator << (ostream& os, PS& a) {

    Output(a);

    return os;
}

istream& operator >> (istream& is, PS& a) {

    Input(a);

    return is;
}