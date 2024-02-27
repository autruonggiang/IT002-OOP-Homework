#pragma once
#include<iostream>
#include<string>

using namespace std;

long long int UCLN(long long int, long long int);

class PS {

public:
    long long int tu;
    long long int mau;

    PS(long long int InputTu, long long int InputMau) {
        this->tu = InputTu;
        this->mau = InputMau;
    }

    PS(long long int InputTu) {
        this->tu = InputTu;
        this->mau = 1;
    }

    PS() {}

    friend void RutGon(PS&);

    // For class PS
    friend PS Minus(PS, PS);

    friend PS Plus(PS, PS);

    friend PS Multiply(PS, PS);

    friend PS Devine(PS, PS);

    friend PS operator + (PS PS1, PS PS2) {
        return Plus(PS1, PS2);
    }

    friend PS operator - (PS PS1, PS PS2) {
        return Minus(PS1, PS2);
    }

    friend PS operator * (PS PS1, PS PS2) {
        return Multiply(PS1, PS2);
    }

    friend PS operator / (PS PS1, PS PS2) {
        return Devine(PS1, PS2);
    }

    friend bool operator == (PS PS1, PS PS2) {
        if (PS1.tu == PS2.tu && PS1.mau == PS2.mau)
            return true;
        else
            return false;
    }

    friend bool operator != (PS PS1, PS PS2) {
        if (PS1.tu != PS2.tu || PS1.mau != PS2.mau)
            return true;
        else
            return false;
    }

    friend bool operator > (PS PS1, PS PS2) {
        PS b = Minus(PS1, PS2);
        if (b.tu <= 0 || b.mau < 0) {
            if (b.tu < 0 && b.mau < 0)
                return true;
            else
                return false;
        }

        return true;
    }

    friend bool operator >= (PS PS1, PS PS2) {
        PS b = Minus(PS1, PS2);
        if (b.tu < 0 || b.mau < 0) {
            if (b.tu < 0 && b.mau < 0)
                return true;
            else
                return false;
        }

        return true;
    }

    friend bool operator < (PS PS1, PS PS2) {
        PS b = Minus(PS2, PS1);
        if (b.tu < 0 || b.mau < 0) {
            if (b.tu < 0 && b.mau < 0)
                return false;
            else
                return true;
        }

        return false;
    }

    friend bool operator <= (PS PS1, PS PS2) {
        PS b = Minus(PS2, PS1);
        if (b.tu <= 0 || b.mau < 0) {
            if (b.tu < 0 && b.mau < 0)
                return false;
            else
                return true;
        }

        return false;
    }

    friend ostream& operator << (ostream& os, PS& a);
    friend istream& operator >> (istream& is, PS& a);

};

bool CheckInt(float);

void Input(PS&);

void Output(PS& a);
