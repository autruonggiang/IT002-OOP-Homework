#include<iostream>
#include<string>
#include<math.h>

using namespace std;

#define MAX 100

typedef class Point {
    
    int x;
    int y;
    
public:
    
    Point () {x = 0; y = 0;}
    Point (int x, int y): 
        x(x), 
        y(y) 
    {};
    
    void InputWithoutCheck ();
    void Input ();
    void Output (string);
    Point Move(int, int);
    float Disctance (Point);
    
} P;

void P::InputWithoutCheck () {
    cout << "Nhap toa do x, y (VD: 5 2): ";
    cin >> x >> y;
}

void P::Input () {
    bool bInput = false;
    
    string select;
    do {
        cout << "Ban co muon nhap khong ? (Y hoac N): ";
        cin >> select;

        if ((select == "y" || select == "y") || (select == "N" || select == "n")) {
            if (select == "y" || select == "y")
                bInput = true;
            else
                bInput = false;
        } else {
            cout << "Y or N (Yes hoac No) !" << endl;
            bInput = true;
        }
    } while ((select != "Y" && select != "y") && (select != "N" && select != "n"));
    
    if (bInput) {
        this->InputWithoutCheck();
    }
}

void P::Output (string NameVecto) {
    cout << "[Vecto] " << NameVecto << "( " << x << ", " << y << " )" << endl;
}

P P::Move (int Vx, int Vy) {
    P c(x + Vx, y + Vy);
    return c;
}

float P::Disctance (Point b) {
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

typedef class TamGiac {
    
    P Diem[3];
    
public:
    TamGiac () {};
    TamGiac (P A, P B, P C) {
        Diem[0] = A;
        Diem[1] = B;
        Diem[2] = C;
    }
    
    friend bool IsTG(TamGiac*);
    void Input ();
    void Output ();
    TamGiac Move (int, int);
    float ChuVi ();
    float DienTich ();
    
} TG;

bool IsTG (TamGiac *A) {
    
    float a = A->Diem[0].Disctance(A->Diem[1]);
    float b = A->Diem[1].Disctance(A->Diem[2]);
    float c = A->Diem[2].Disctance(A->Diem[0]);
    
    if ((a + b > c) && (a + c > b) && (b + c > a))
        return true;
    
    return false;
}

void TG::Input () {
    bool bInput = false;
    
    string select;
    do {
        cout << "Ban co muon nhap khong ? (Y hoac N): ";
        cin >> select;

        if ((select == "y" || select == "y") || (select == "N" || select == "n")) {
            if (select == "y" || select == "y")
                bInput = true;
            else
                bInput = false;
        } else {
            cout << "Y or N (Yes hoac No) !" << endl;
            bInput = true;
        }
    } while ((select != "Y" && select != "y") && (select != "N" && select != "n"));
    
    if (bInput) {
        do {
            for (int i = 0; i < 3; ++i) {
                Diem[i].InputWithoutCheck();
            }
            
            if (!IsTG(this)) {
                cout << "3 diem tren khong tao thanh mot tam giac !" << endl;
            }
        } while (!IsTG(this));
    }
}

void TG::Output () {
    
    Diem[0].Output("A: ");
    Diem[1].Output("B: ");
    Diem[2].Output("C: ");
}

TG TG::Move (int Vx, int Vy) {
    TG c (Diem[0].Move(Vx, Vy), Diem[1].Move(Vx, Vy), Diem[2].Move(Vx, Vy));
    
    return c;
}

float TG::ChuVi () {
    float sum;
    
    float a = Diem[0].Disctance(Diem[1]);
    float b = Diem[1].Disctance(Diem[2]);
    float c = Diem[2].Disctance(Diem[0]);
    
    sum = a + b + c;
    
    return sum;
}

float TG::DienTich () {
    float p = this->ChuVi()/2;
    
    float a = Diem[0].Disctance(Diem[1]);
    float b = Diem[1].Disctance(Diem[2]);
    float c = Diem[2].Disctance(Diem[0]);
    
    
    float S = sqrt(p * (p - a) * (p - b) * (p - c));
    
    return S;
}

void IOutput (TG List[], int &num) {
    
    cout << "Nhap so luong tam giac: ";
    cin >> num;
    
    string Text;
    for (int i = 0; i < num; ++i) {
        Text = "Tam giac: " + to_string(i);
        
        cout << endl << Text << endl;
        List[i].Input();
    }
    
    cout << "\n____________________________" << endl;
    for (int i = 0; i < num; ++i) {
        Text = "Tam giac: " + to_string(i);
        cout << Text << endl;
        List[i].Output();
        cout << endl;
    }
    
}

void FindMaxMin (TG List[], int num) {
    cout << "\n____________________________" << endl;
    
    TG maxCTG = List[0];
    float maxC = List[0].ChuVi();
    TG maxSTG = List[0];
    float maxS = List[0].DienTich();
    
    for (int i = 1; i < num; ++i) {
        if (List[i].ChuVi() > maxC) {
            maxCTG = List[i];
            maxC = List[i].ChuVi();
        }
        
        if (List[i].DienTich() > maxS) {
            maxSTG = List[i];
            maxS = List[i].DienTich();
        }
        
    }
    
    cout << "Tam giac co chu vi lon nhat: " << endl;
    maxCTG.Output();
    
    cout << "\nTam giac co dien tich lon nhat: " << endl;
    maxSTG.Output();
    
}

void TinhTien (TG List[], int num) {
    cout << "\n____________________________" << endl;
    
    string Text;
    
    int x, y;
    cout << "Nhap toa do vecto (VD: 3 -2): ";
    cin >> x >> y;
    
    for (int i = 0; i < num; ++i) {
        Text = "Tam giac: " + to_string(i);
        cout << Text << endl;
        List[i].Move(x, y).Output();
        cout << endl;
    }
    
}

int main() {
    
	TG List[MAX];
    int num;
    
    IOutput(List, num);
    FindMaxMin(List, num);
    TinhTien(List, num);
	
	return 0;
}
