#include <iostream>
#include <limits>

using namespace std;


bool isInt(float num) {
    int test = num;
    if (num == test)
        return true;
    
    return false;
}

void InputInt(int &num, string Text) {
        
    float temp;
    do {
        cout << Text;
        cin >> temp;
        
        if (!isInt(temp))
            cout << "So phai nguyen !" << endl;
    } while (!isInt(temp));
    
    num = temp;
}

typedef class Employee {
    
public:

    string Ma_nhan_vien;
    string Ho_ten;
    string Phong_ban;
    int Base_salary;
    int Bonus;
    
    void Input() {
        cin.clear();
        cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' ); 
        
        cout << "Ma nhan vien: ";
        getline(cin, this->Ma_nhan_vien);
        
        cout << "Ho va ten: ";
        getline(cin, this->Ho_ten);
        
        cout << "Phong ban: ";
        getline(cin, this->Phong_ban);
        
        InputInt(this->Base_salary, "Nhap luong co ban: ");
        InputInt(this->Bonus, "Nhap thuong: ");
    }
    
    void Print() {
        cout << "Ma nhan vien: " << this-> Ma_nhan_vien << endl;
        cout << "Ho va ten: " << this->Ho_ten << endl;
        cout << "Phong ban: " <<  this->Phong_ban << endl;
        cout << "Luong co ban: " << this->Base_salary << endl;
        cout << "Thuong: " << this->Base_salary << endl;
        cout << "Thuc lanh: " << this->RealSalary() << endl;
    }
    
    
    int RealSalary() {
        return this->Base_salary + this->Bonus;
    }
    
} Emp;

void Input(Emp *&Employees, int &n) {

    InputInt(n, "Nhap so luong nhan vien: ");
    Employees = new Emp[n];
    
    cout << endl;
    for (int i = 0; i < n; ++i) {
        Employees[i].Input();
        cout << endl;
    }
    
}

int SumRealSalary(Emp *Employees, int n) {
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
        sum += Employees[i].RealSalary();
    }
    
    return sum;
}

void PrintLowestSalry(Emp *Employees, int n) {
    int minSlary = Employees[0].Base_salary;
    Emp LowSalary[n];
    LowSalary[0] = Employees[0];
    int index = 1;
    
    Emp Employ;
    for (int i = 1; i < n; ++i) {
        Employ = Employees[i];
        
        if (Employ.Base_salary <= minSlary) {
            if (Employ.Base_salary == minSlary) {
                LowSalary[index] = Employ;
            } else {
                index = 0;
                minSlary = Employ.Base_salary;
            }
            
            LowSalary[index] = Employ;
            index++;
        }
    }
    
    cout << "Nhung nhan vien co muc luong co ban thap nhat la:" << endl;
    for (int i = 0; i < index; ++i) {
        LowSalary[i].Print();
        cout << endl;
    }
    
}

int CountBonus(Emp *Employees, int n, int limit) {
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (Employees[i].Bonus >= limit)
            count++;
    }
    
    return count;
}

string LowerCase(string Text) {
    
    string temp = "";
    for (int i = 0; i < Text.length(); ++i) {
        if (Text[i] < 'a' && Text[i] >= 'A' && Text[i] <= 'Z') {
            Text[i] += 32;
        }
        
        temp += Text[i];
    }
    
    return temp;
}

void Swap(Emp *&Employees, int a, int b) {
    
    Emp temp = Employees[a];
    
    Employees[a] = Employees[b];
    Employees[b] = temp;
}

int Check(string a, string b, int index = 0) {
    if (a == b)
        return 0;
    
    if (a[index] > b[index])
        return 1;
    else if (a[index] == b[index])
        return Check(a, b, ++index);
    else
        return -1;
}

void Sort(Emp *&Employees, int n) {
    
    bool Run = false;
    string temp1, temp2;
    Emp Employ;
    int temp;
    for (int i = 0; i < n-1; ++i) {
        
        temp1 = LowerCase(Employees[i].Phong_ban);
        temp2 = LowerCase(Employees[i+1].Phong_ban);
        
        temp = Check(temp1, temp2);
        if (temp == 1) {
            Swap(Employees, i, i+1);
            Run = true;
        } else if (temp == 0) {
            if (Check(Employees[i].Ma_nhan_vien, Employees[i+1].Ma_nhan_vien) == -1) {
                Swap(Employees, i, i+1);
                Run = true;
            }
        }
    }
    
    if (Run)
        Sort(Employees, n);
}

int main () {
    Emp *Employees;
    int n;
    Input(Employees, n);

    cout << "\n_______________________________________________" << endl;
    cout << "Tong thuc lanh tat ca nhan vien la: " << SumRealSalary(Employees, n) << endl;

    cout << endl;
    cout << "\n_______________________________________________" << endl;
    PrintLowestSalry(Employees, n);
    
    int limit = 1200000;
    cout << "_______________________________________________" << endl;
    cout << "Nhung nhan vien co muc thuong >= " << limit << ": " << CountBonus(Employees, n, limit) << endl;
    
    cout << "\n_______________________________________________" << endl;
    cout << "Sap xep nhan vien theo thu tu tang dan: " << endl;
    Sort(Employees, n);
    for (int i = 0; i < n; ++i) {
        Employees[i].Print();
        cout << endl;
    }
    
    return 0;
}
