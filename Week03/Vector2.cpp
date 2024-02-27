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
    
    void Input ();
    void Output (string);
    Point Move(int, int);
    float Disctance (Point);
    
} P;

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
        cout << "Nhap toa do x, y (VD: 3 -2): ";
        cin >> x >> y;
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

void IOutput (P List[], int &num) {
    
    cout << "Nhap so luong diem: ";
    cin >> num;
    
    string Text;
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i);
        
        cout << endl << Text << endl;
        
        List[i].Input();
    }
    
    cout << "\n_____________________________" << endl;
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i);
        List[i].Output(Text);
    }
    
}

void FindMaxMin (P List[], int num) {
    cout << "\n_____________________________" << endl;
    
    float max = List[0].Disctance(List[1]);
    float min = List[0].Disctance(List[1]);
    
    float dis;
    for (int i = 0; i < num-1; ++i) {
        for (int j = i + 1; j < num-1; ++j) {
            dis = List[i].Disctance(List[j]);
            
            if (dis > max) {
                max = dis;
            }
            
            if (min > dis) {
                min = dis;
            }
        }
    }
    
    cout << "Khoang cach lon nhat: " << max << endl;
    cout << "Khoang cach nho nhat: " << min << endl;
    
}

void TinhTien (P List[], int num) {
    cout << "\n_____________________________" << endl;
    
    string Text;
    
    int x, y;
    cout << "Nhap toa do vecto (VD: 3 -2): ";
    cin >> x >> y;
    
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i);
        List[i].Move(x, y).Output(Text);
    }
}

int main() {
	
	P List[MAX];
    int num;
    
    IOutput(List, num);
    FindMaxMin(List, num);
    TinhTien(List, num);
	
	return 0;
}
