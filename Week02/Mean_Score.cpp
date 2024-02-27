#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool CanStoi(string s) {
    string temp;
    for (long unsigned int i = 0; i < s.length(); ++i) {
        temp = "";
        temp += s[i];
        if (to_string(s[i] - '0') != temp)
            return false;
    }
    
    return true;
}

bool ValidDate(string sDate) {
    sDate += "/";
    
    string temp = "";
    int num[3];
    
    int check = 0;
    for (long unsigned int i = 0; i < sDate.length(); ++i) {
        if (sDate[i] == '/') {
            if (CanStoi(temp))
                num[check] = stoi(temp);
            else
                return false;
            check++;
            temp = "";
        } else {
            temp += sDate[i];
        }
    }
    
    if (check != 3)
        return false;
    
    if (num[0] < 1 || num[1] > 12 || num[1] < 0 || num[2] < 0)
        return false;
    
    if (num[1] == 2) {
        if (num[2]%4 == 0) {
            if (num[0] > 29)
                return false;
        } else {
            if (num[0] > 28)
                return false;
        }
    }
    
    if (num[1] == 4 || num[1] == 6 || num[1] == 9) {
        if (num[0] > 30)
            return false;
    } else {
        if (num[0] > 31)
            return false;
    }
    
    return true;
}

typedef struct Date {
    
    int iDay, iMonth, iYear;
    
    void Input(string sDate) {
        sDate += "/";
        
        string temp = "";
        int num[3];
        
        int check = 0;
        for (long unsigned int i = 0; i < sDate.length(); ++i) {
            if (sDate[i] == '/') {
                num[check] = stoi(temp);
                check++;
                temp = "";
            } else {
                temp += sDate[i];
            }
        }
        
        this->iDay = num[0];
        this->iMonth = num[1];
        this->iYear = num[2];
    }
    
    void PrintFixNum(int num) {
        if (num < 10)
            cout << "0" << num;
        else
            cout << num;
    }
    
    void Print() {
        PrintFixNum(this->iDay);
        cout << "/";
        PrintFixNum(this->iMonth);
        cout << "/" << this->iYear << endl; 
    }
    
    bool Bigger(Date new_Date) {
        if (this->iYear > new_Date.iYear)
            return true;
        else if (this->iYear == new_Date.iYear) {
            if (this->iMonth > new_Date.iMonth)
                return true;
            else if (this->iMonth == new_Date.iMonth) {
                if (this->iDay > new_Date.iDay)
                    return true;
            }
        }
        return false;
    }
    
    bool operator > (Date new_Date) {
        return (!Bigger(new_Date));
    }
    
    bool operator < (Date new_Date) {
        return Bigger(new_Date);
    }
    
    bool operator == (Date new_Date) {
        
        if (this->iYear  == new_Date.iYear && 
            this->iMonth == new_Date.iMonth && 
            this->iDay   == new_Date.iDay)
            return true;
        else
            return false;
    }
    
} Date;

Date NextDate(Date Date1) {

    Date1.iDay++;
    
    if (Date1.iYear % 4 == 0) {
        if (Date1.iMonth == 2) {
            if (Date1.iDay == 30) {
                Date1.iDay = 1;
                Date1.iMonth++;
            }
        }
    } else {
        if (Date1.iMonth == 2) {
            if (Date1.iDay == 29) {
                Date1.iDay = 1;
                Date1.iMonth++;
            }
        }
        
    }

    if (Date1.iMonth == 4 || 
        Date1.iMonth == 6 || 
        Date1.iMonth == 9 ) {
        
        if (Date1.iDay == 31) {
            Date1.iDay = 1;
            Date1.iMonth++;
        }
        
    } else if (Date1.iMonth != 2) {
        if (Date1.iDay == 32) {
            Date1.iDay = 1;
            Date1.iMonth++;
        }
    }
    
    if (Date1.iMonth > 12) {
        Date1.iDay = 1;
        Date1.iMonth = 1;
    }
    
    return Date1;
}

void InputDate(Date &date) {
    
    string sInputDate;
    do {
        cout << "Nhap ngay sinh (VD: 01/01/2000): ";
        getline(cin, sInputDate);
        
        if (!(ValidDate(sInputDate)))
            cout << "Ngay sinh khong hop le !" << endl;
    } while (!(ValidDate(sInputDate)));
    
    date.Input(sInputDate);
}

istream& operator >> (istream &is, Date &date) {
    InputDate(date);
    
    return is;
}

ostream& operator << (ostream &os, Date &date) {
    date.Print();
    
    return os;
}

class Student {
    
    string ho_ten;
    float toan, van;
    
public:

    void InputDiem(float &diem, string Mon) {
        do {
            cout << "Nhap diem " << Mon << ": ";
            cin >> diem;
            if (diem < 0) {
                cout << "Diem phai lon hon 0 !" << endl;
            } else if (diem > 10)
                cout << "Diem phai nho hon 10 ! " << endl;
        } while (diem < 0 || diem > 10);
    }

    void Input() {
        
        cout << "Ho va ten: ";
        getline(cin, this->ho_ten);
        
        InputDiem(this->toan, "toan");
        InputDiem(this->van, "van");
    }
    
    float DiemTB() {
        return (this->toan + this->van)/2;
    }
};

istream& operator >> (istream &is, Student &stu) {
    stu.Input();
    
    return is;
}

typedef Student stu;

int main() {
    
    Date date;
    cin >> date;
    cout << "Ngay ke tiep: ";
    NextDate(date).Print();
    cout << endl;
    
    stu Student;
    cin >> Student;
    
    cout << "___________________________________" << endl;
    cout << "Diem trung binh cua hoc sinh la: " << Student.DiemTB();
    
    return 0;
}
