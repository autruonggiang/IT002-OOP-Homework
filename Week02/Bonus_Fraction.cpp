#include<iostream>
#include<string>

using namespace std;

long long int UCLN(long long int m, long long int n) {

    long long int num;
    m = (m < 0)? -m: m;
    n = (n < 0)? -n: n;

    if (m < n) {
        num = n;
        n = m;
        m = num;
    }

    if (n == 0 || m == n)
        return m;
    return UCLN(n, m%n);
}

class PS {
    
    public:
        long long int tu;
        long long int mau;

        PS (long long int InputTu, long long int InputMau) {
            this->tu = InputTu;
            this->mau = InputMau;
        }
        
        PS () {}
        
        void RutGon(PS &new_PS) {
            long long int num = UCLN(new_PS.tu, new_PS.mau);
            new_PS.tu = new_PS.tu/num;
            new_PS.mau = new_PS.mau/num;
        }

        
        PS Minus(PS PS2) {
            PS new_PS;
            new_PS.mau = mau * PS2.mau;
            new_PS.tu = tu*PS2.mau - PS2.tu*mau;
            RutGon(new_PS);

            return new_PS;
        }
        
        PS Plus(PS PS2) {
            PS new_PS;
            new_PS.mau = mau * PS2.mau;
            new_PS.tu = tu*PS2.mau + PS2.tu*mau;

            RutGon(new_PS);

            return new_PS;
        }
        
        PS Multiply(PS PS2) {
            PS new_PS;
            long long int numTu = UCLN(tu, PS2.mau);
            long long int numMau = UCLN(mau, PS2.tu);
            
            new_PS.mau = mau/numMau * PS2.mau/numTu;
            new_PS.tu = tu/numTu * PS2.tu/numMau;        
            
            RutGon(new_PS);

            return new_PS;
        }
        
        PS Devine(PS PS2) {
            PS new_PS;
            new_PS.mau = mau * PS2.tu;
            new_PS.tu = tu * PS2.mau;

            RutGon(new_PS);

            return new_PS;
        }
        
        PS Multiply (long long int a) {
            PS new_PS;
            
            long long int numMau = UCLN(a, mau);
            
            new_PS.tu = tu * a/numMau;
            new_PS.mau = mau/numMau;

            RutGon(new_PS);

            return new_PS;
        }

        PS Devine (long long int a) {
            PS new_PS;

            new_PS.tu = tu;
            new_PS.mau = mau * a;

            RutGon(new_PS);

            return new_PS;
        }

        PS Plus (long long int a) {
            PS new_PS;

            new_PS.tu = tu + a;
            new_PS.mau = mau * a;

            RutGon(new_PS);

            return new_PS;
        }

        PS Minus (long long int a) {
            PS new_PS;

            new_PS.tu = tu - a;
            new_PS.mau = mau * a;

            RutGon(new_PS);

            return new_PS;
        }
        
        PS operator + (PS PS2) {
            return Plus(PS2);
        }

        PS operator - (PS PS2) {
            return Minus(PS2);
        }

        PS operator * (PS PS2) {
            return Multiply(PS2);
        }

        PS operator / (PS PS2) {
            return Devine(PS2);
        }

        PS operator * (long long int a) {
            return Multiply(a);
        }

        PS operator / (long long int a) {
            return Devine(a);
        }

        PS operator + (long long int a) {
            return Plus(a);
        }

        PS operator - (long long int a) {
            return Minus(a);
        }

        bool operator == (PS a) {
            if (tu == a.tu && mau == a.mau)
                return true;
            else
                return false;
        }

        bool operator == (long long int a) {
            if (tu/mau  == a)
                return true;
            else
                return false;
        }

        bool operator != (PS a) {
            if (tu != a.tu || mau != a.mau)
                return true;
            else
                return false;
        }

        bool operator != (long long int a) {
            if (tu/mau  != a)
                return true;
            else
                return false;
        }
        
        bool operator > (PS a) {
            PS b = Minus(a);
            if (b.tu <= 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return true;
                else
                    return false;
            }
            
            return true;
        }
        
        bool operator >= (PS a) {
            PS b = Minus(a);
            if (b.tu < 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return true;
                else
                    return false;
            }
            
            return true;
        }
        
        bool operator < (PS a) {
            PS b = Minus(a);
            if (b.tu < 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return false;
                else
                    return true;
            }
            
            return false;
        }
        
        bool operator <= (PS a) {
            PS b = Minus(a);
            if (b.tu <= 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return false;
                else
                    return true;
            }
            
            return false;
        }
        
        bool operator > (long long int a) {
            PS b = Minus(a);
            if (b.tu <= 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return true;
                else
                    return false;
            }
            
            return true;
        }
        
        bool operator >= (long long int a) {
            PS b = Minus(a);
            if (b.tu < 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return true;
                else
                    return false;
            }
            
            return true;
        }
        
        bool operator < (long long int a) {
            PS b = Minus(a);
            if (b.tu < 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return false;
                else
                    return true;
            }
            
            return false;
        }
        
        bool operator <= (long long int a) {
            PS b = Minus(a);
            if (b.tu <= 0 || b.mau < 0) {
                if (b.tu < 0 && b.mau < 0)
                    return false;
                else
                    return true;
            }
            
            return false;
        }
        
};

bool CheckInt(float num) {
    int test = num;
    if (test == num)
        return true;
    
    return false;
}

void Input(PS &a) {
    
    float tu, mau;
    
    do {
        cout << "Nhap tu so nguyen: ";
        cin >> tu;
        
        if (!CheckInt(tu)) {
            cout << "Tu so phai nguyen!" << endl;
        }
        
    } while (!CheckInt(tu));
    
    do {
        cout << "Nhap mau so nguyen: ";
        cin >> mau;
        
        if (!CheckInt(mau)) {
            cout << "Mau so phai nguyen !" << endl;
        } else if (mau == 0) {
            cout << "Mau so phai khac 0 !" << endl;
        }
        
    } while (!CheckInt(mau) || mau == 0);
    
    a.tu = tu;
    a.mau = mau;
}

void Output(PS &a) {
    if (a.tu == 0)
        cout << "0";
    else if ((a.tu < 0 && a.mau < 0) || (a.tu > 0 && a.mau < 0))
        cout << -1*a.tu << "/" << -1*a.mau;
    else
        cout << a.tu << "/" << a.mau;
}

ostream& operator << (ostream& os, PS &a) {
    
    Output(a);
    
    return os;
}

istream& operator >> (istream& is, PS &a) {
    
    Input(a);
    
    return is;
}

void Solve(PS &a, PS &b) {
    PS c = a+b;
    cout << "a + b = " << c << endl;
    
    c = a-b;
    cout << "a - b = " << c << endl;
    
    c = a*b;
    cout << "a * b = " << c << endl;
    
    c = a/b;
    cout << "a / b = " << c << endl;
}

int main () {
    
    cout << "---------- Nhap, xuat phan so ----------" << endl;
    PS a, b;
    cout << "Phan so thu nhat\n";
    cin >> a;
    cout << "\nPhan so thu hai\n";
    cin >> b;
    
    cout << "_______________________________\n";
    cout << "Phan so thu nhat: " << a << endl;
    cout << "Phan so thu hai: " << b << endl;
    
    cout << endl;
    cout << "---------- Tinh toan hai phan so ----------" << endl;
    Solve(a, b);
    
    return 0;
}
