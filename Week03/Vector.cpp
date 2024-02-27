#include<iostream>
#include<math.h>

using namespace std;

#define MAX 100

inline bool IsInt (float Num) {
    int test = Num;
    bool check = test == Num;
    
    return check;
}

void InputInt(int &Num, string Text) {
    float test;
    
    do {
        cout << Text;
        cin >> test;
        
        if (!IsInt(test))
            cout << "So phai nguyen !" << endl;
        else if (test < 0)
    cout << "So nguyen phai lon hon 0 !" << endl;
        
    } while (!IsInt(test) || test < 0);
    
    Num = test;
}

typedef class Vector {
    int Head;
    int Tail;
    int Size = 0;
    int List[MAX];
    
public:
    
    void Input();
    void Output(string);
    Vector Cong (Vector);
    Vector Tru (Vector);
    Vector Move (Vector);
    float Norm ();
    
} VT;

void VT::Input () {
    InputInt(Size, "Nhap so luong so thuc: ");
    
    for (int i = 0; i < Size; ++i) {
        cout << "Nhap so thu " << i << ": ";
        cin >> List[i];
    }
    
    Head = List[0];
    Tail = List[Size - 1];
    
}

void VT::Output (string NameVecto) {
    cout << "[Vecto] " << NameVecto << "( ";
    
    for (int i = 0; i < Size; ++i) {
        cout << List[i];
        
        if (i < Size - 1)
            cout << ", ";
        else 
            cout << " ";
    }
    
    cout << ")" << endl;
}

VT VT::Cong (VT b) {
    
    VT c;
    
    int size = 0;
    for (int i = 0; i < max(Size, b.Size); ++i, ++size) {
        if (Size < b.Size)
            if (i >= Size)
                c.List[i] = b.List[i];
            else 
                c.List[i] = List[i] + b.List[i];
        else if (b.Size < Size)
            if (i >= b.Size)
                c.List[i] = List[i];
            else
                c.List[i] = List[i] + b.List[i];
        else
            c.List[i] = List[i] + b.List[i];
    }
    
    c.Size = size;
    c.Head = c.List[0];
    c.Tail = c.List[size - 1];
    
    return c;
}

VT VT::Tru (VT b) {
    
    VT c;
    
    int size = 0;
    for (int i = 0; i < max(Size, b.Size); ++i) {
        if (Size < b.Size)
            if (i >= Size)
                c.List[i] = -1 * b.List[i];
            else 
                c.List[i] = List[i] - b.List[i];
        else if (b.Size < Size)
            if (i >= b.Size)
                c.List[i] = List[i];
            else
                c.List[i] = List[i] - b.List[i];
        else
            c.List[i] = List[i] - b.List[i];
            
        size++;
    }
    
    c.Size = size;
    c.Head = c.List[0];
    c.Tail = c.List[size - 1];
    
    return c;
}

VT VT::Move (VT b) {
    VT c;
    
    if (Size == b.Size) {
        c = this->Cong(b);
    } else {
        cout << "So chieu cua A phai giong B !" << endl;
    }
    
    return c;
}

float VT::Norm () {
    float sum = 0;
    
    for (int i = 0; i < Size; ++i) {
        sum += pow(List[i], 2);
    }
    
    return sqrt(sum);
}

void swap (VT List[MAX], int a, int b) {
    VT temp = List[a];
    List[a] = List[b];
    List[b] = temp;
}

void Sort(VT List[MAX], int num) {
    bool run = false;
    
    for (int i = 0; i < num - 1; ++i) {
        if (List[i].Norm() > List[i+1].Norm()) {
            swap(List, i, i+1);
            run = true;
        }
    }
    
    if (run)
        Sort(List, num);
}

void PrintList (VT List[MAX], int num) {
    
    string Text = "";
    
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i) + ": ";
        List[i].Output(Text);
    }
}

int main() {
	
    int num;
    cout << "Nhap so luong vecto: ";
    cin >> num;
    
    VT List[num];
    string Text;
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i) + ": ";
        
        cout << "\nVecto " << Text << endl;
        List[i].Input();
        List[i].Output(Text);
    }
    
    cout << "\n_____________________________" << endl;
    cout << "Cac vecto sap xep tang dan theo Norm: " << endl;
    Sort(List, num);
    PrintList(List, num);

    cout << "\n_____________________________" << endl;
    cout << "Tinh tien vecto theo chinh no: " << endl;
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i) + ": ";
        
        cout << "\nVecto: " << Text << endl;
        List[i].Move(List[i]).Output(Text);
    }
    
    cout << "\n_____________________________" << endl;
    cout << "Tinh tong hieu cac vecto khac voi chinh no: " << endl;
    for (int i = 0; i < num; ++i) {
        Text = "A" + to_string(i) + ": ";
        
        cout << "\nVecto: " << Text << endl;
        
        for (int j = 0; j < num; ++j) {
            if (i != j) {
                List[i].Cong(List[j]).Output("A + B\n");
                List[i].Tru(List[j]).Output("A - B\n");
            }
        }
        
    }
    
	return 0;
}
