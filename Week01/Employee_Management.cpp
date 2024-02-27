#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool CanStoi (string s) 
{
    string temp;
    for (int i = 0; i < s.length(); ++i) 
	{
        temp = "";
        temp += s[i];
        if (to_string(s[i] - '0') != temp)
            return false;
    }
    
    return true;
}

bool ValidDate (string sDate) 
{
    sDate += "/";
    
    string temp = "";
    int num[3];
    
    int check = 0;
    for (int i = 0; i < sDate.length(); ++i) 
	{
        if (sDate[i] == '/') 
		{
            if (CanStoi (temp))
                num[check] = stoi(temp);
            else
                return false;
            check++;
            temp = "";
        } else 
		{
            temp += sDate[i];
        }
    }
    
    if (check != 3)
        return false;
    
    if (num[0] < 1 || num[1] > 12 || num[1] < 0 || num[2] < 0)
        return false;
    
    if (num[1] == 2) 
	{
        if (num[2]%4 == 0) 
		{
            if (num[0] > 29)
                return false;
        } else {
            if (num[0] > 28)
                return false;
        }
    }
    
    if (num[1] == 4 || num[1] == 6 || num[1] == 9) 
	{
        if (num[0] > 30)
            return false;
    } else {
        if (num[0] > 31)
            return false;
    }
    
    return true;
}

typedef struct Date 
{
    
    int iDay, iMonth, iYear;
    
    void Input (string sDate) 
	{
        sDate += "/";
        
        string temp = "";
        int num[3];
        
        int check = 0;
        for (int i = 0; i < sDate.length(); ++i) 
		{
            if (sDate[i] == '/') 
			{
                num[check] = stoi(temp);
                check++;
                temp = "";
            } else 
			{
                temp += sDate[i];
            }
        }
        
        this->iDay = num[0];
        this->iMonth = num[1];
        this->iYear = num[2];
    }
    
    void PrintFixNum (int num) 
	{
        if (num < 10)
            cout << "0" << num;
        else
            cout << num;
    }
    
    void Print() 
	{
        PrintFixNum (this->iDay);
        cout << "/";
        PrintFixNum (this->iMonth);
        cout << "/" << this->iYear << endl; 
    }
    
    bool Bigger (Date new_Date) 
	{
        if (this->iYear > new_Date.iYear)
            return true;
        else if (this->iYear == new_Date.iYear) 
		{
            if (this->iMonth > new_Date.iMonth)
                return true;
            else if (this->iMonth == new_Date.iMonth) 
			{
                if (this->iDay > new_Date.iDay)
                    return true;
            }
        }
        return false;
    }
    
    bool operator > (Date new_Date) 
	{
        return (!Bigger (new_Date));
    }
    
    bool operator < (Date new_Date) 
	{
        return Bigger (new_Date);
    }
    
    bool operator == (Date new_Date) 
	{
        
        if (this->iYear  == new_Date.iYear && 
            this->iMonth == new_Date.iMonth && 
            this->iDay   == new_Date.iDay)
            return true;
        else
            return false;
    }
    
} Date;

void PrintDate (Date &dDate) 
{
    dDate.Print();
}

class Employee 
{
    
    string sName;
    Date dDate;
    string sType;
    int iBaseSalary = 0;
    
    int iEfficiency = 0;
    int iRate = 0;
    

public:
    
    void Input () 
	{
        
        cout << "Ho va ten: ";
        getline(cin, this->sName);
        
        string sInputDate;
        cout << "Ngay thang nam sinh (VD: 01/01/1971): ";
        getline(cin, sInputDate);
        
        while (!(ValidDate (sInputDate))) 
		{
            cout << "Ngay thang nam khong hop le !" << endl;
            cout << "Ngay thang nam sinh (VD: 01/01/1971): ";
            getline(cin, sInputDate);
        }
        
        this->dDate.Input (sInputDate);
        
        cout << "Loai nhan vien (Nhan vien van phong hoac Nhan vien san xuat): ";
        getline(cin, sType);
        
        while (this->sType != "Nhan vien van phong" && this->sType != "Nhan vien san xuat") 
		{
            cout << "Loai nhan vien khong hop le !" << endl;
            cout << "Loai nhan vien (Nhan vien van phong hoac Nhan vien san xuat): ";
            getline(cin, sType);
        }
        
        if (this->sType == "Nhan vien san xuat") 
		{
            cout << "Luong can ban: ";
            cin >> this->iBaseSalary;
            cout << "So san pham: ";
            cin >> this->iEfficiency;
            this->iRate = 5000;
        } else 
		{
            cout << "So ngay lam viec: ";
            cin >> this->iEfficiency;
            this->iRate = 100000;
        }
        
        cin.clear();
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
    
    void InputWithoutType (string Type) 
	{
        this->sType = Type;
        
        cout << "Ho va ten: ";
        getline(cin, this->sName);
        
        string sInputDate;
        cout << "Ngay thang nam sinh (VD: 01/01/1971): ";
        getline(cin, sInputDate);
        
        while (!(ValidDate (sInputDate))) 
		{
            cout << "Ngay thang nam khong hop le !" << endl;
            cout << "Ngay thang nam sinh (VD: 01/01/1971): ";
            getline(cin, sInputDate);
        }
        
        this->dDate.Input (sInputDate);
        
        if (this->sType == "Nhan vien san xuat") {
            cout << "Luong can ban: ";
            cin >> this->iBaseSalary;
            cout << "So san pham: ";
            cin >> this->iEfficiency;
            this->iRate = 5000;
        } else 
		{
            cout << "So ngay lam viec: ";
            cin >> this->iEfficiency;
            this->iRate = 100000;
        }
        
        cin.clear();
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
    
    void PrintFull() 
	{
        cout << "Ho va ten: " << this->sName << endl;
        cout << "Ngay thang nam sinh (VD: 01/01/1971): ";
        PrintDate(this->dDate);
        cout << "Loai nhan vien: " << this->sType << endl;
        if (this->sType == "Nhan vien san xuat") 
		{
            cout << "Luong can ban: " << this->iBaseSalary << endl;
            cout << "So san pham: " << this->iEfficiency << endl;
        } else 
		{
            cout << "So ngay lam viec: " << this->iEfficiency << endl;
        }
    }
    
    void PrintBasic() 
	{
        cout << "Ho va ten: " << this->sName << endl;
        cout << "Ngay thang nam sinh (VD: 01/01/1971): ";
        PrintDate (this->dDate);
    }
    
    int PaidSalary () 
	{
        return this->iBaseSalary + this->iEfficiency * this->iRate;
    }
    
    Date GetDate () 
	{
        return this->dDate;
    }
    
};

int SpaceDate (Date Date1, Date Date2) 
{
    
    int space = 0;
    
    if ((Date1.iDay == Date2.iDay) && (Date1.iMonth == Date2.iMonth))
        return space;
    
    Date1.iDay++;
    space++;
    
    if (Date1.iYear % 4 == 0) 
	{
        if (Date1.iMonth == 2) 
		{
            if (Date1.iDay == 30) 
			{
                Date1.iDay = 1;
                Date1.iMonth++;
            }
        }
    } else 
	{
        if (Date1.iMonth == 2) 
		{
            if (Date1.iDay == 29) 
			{
                Date1.iDay = 1;
                Date1.iMonth++;
            }
        }
        
    }

    if (Date1.iMonth == 4 || 
        Date1.iMonth == 6 || 
        Date1.iMonth == 9 ) 
		{
        
        if (Date1.iDay == 31) 
		{
            Date1.iDay = 1;
            Date1.iMonth++;
        }
        
    } else if (Date1.iMonth != 2) 
	{
        if (Date1.iDay == 32) 
		{
            Date1.iDay = 1;
            Date1.iMonth++;
        }
    }
    
    if (Date1.iMonth > 12) 
	{
        Date1.iDay = 1;
        Date1.iMonth = 1;
    }
    
    if (Date1.iMonth <= Date2.iMonth) 
	{
        if (Date1.iMonth == Date2.iMonth) 
		{
            if (Date1.iDay < Date1.iDay) 
			{
                return space + SpaceDate (Date1, Date2);
            } else 
			{                
                return space + SpaceDate (Date2, Date1);
            }
        }
        return space + SpaceDate (Date1, Date2);
    } else 
	{
        return space + SpaceDate (Date2, Date1);
    }
}

void InputEmployee (int start, int num, Employee *&List, string Type) 
{
    if (num > 0)
        cout << Type << "\n---------- Danh sach nhan vien ----------\n";
    
    for (int i = start; i < start + num; ++i) 
	{
        List[i].InputWithoutType(Type);
        cout << endl;
    }
}

void Input (Employee *&List, int &n, int &m) 
{
    
    cout << "So nhan vien van phong: ";
    cin >> n;
    cout << "So nhan vien san xuat: ";
    cin >> m;
    cin.clear();
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    List = new Employee[m+n];
    cout << "\n";
    InputEmployee(0, n, List, "Nhan vien van phong");
    InputEmployee(n, m, List, "Nhan vien san xuat");
    
}

void Output (Employee *List, int num) 
{
    
    for (int i = 0; i < num; ++i) 
	{
        List[i].PrintFull();
        cout << endl;
    }
}

void SwapEmployee (Employee *&List, int pos1, int pos2) 
{
    Employee temp = List[pos1];
    
    List[pos1] = List[pos2];
    List[pos2] = temp;
}

void SortByDate (Employee *&List, int num, int type) 
{
    
    bool stop = true;
    
    for (int i = 0; i < num-1; ++i) 
	{
        if (type == -1) 
		{
            if (List[i].GetDate() < List[i+1].GetDate()) 
			{
                SwapEmployee(List, i, i+1);
                stop = false;
            }
        } else 
		{
            if (List[i].GetDate() > List[i+1].GetDate()) 
			{
                SwapEmployee(List, i, i+1);
                stop = false;
            }
        }
    }
        
    if (!stop)
        SortByDate(List, num, type);
}

int TotalSalary(Employee *List, int num) 
{
    int salary = 0;
    for (int i = 0; i < num; ++i) 
	{
        salary += List[i].PaidSalary();
    }
    
    return salary;
}

Employee ClosestDate (Employee *List, int num, string sDate) 
{
    Employee temp = List[0];
    
    Date dDate;
    dDate.Input(sDate);
    
    int min = SpaceDate (List[0].GetDate(), dDate);
    int space;
    for (int i = 1; i < num; ++i) 
	{
        space = SpaceDate (List[i].GetDate(), dDate);
        if (space < min) 
		{
            temp = List[i];
            min = space;
        }
    }
    return temp;
}

int main() 
{
    
    Employee *List;
    int n, m;
    cout << "---------- Danh sach nhap thong tin nhan vien ----------\n";
    Input (List, n, m);
    
    cout << endl;
    cout << "---------- Danh sach xuat thong tin nhan vien ----------\n";
    Output (List, n+m);
    
    cout << "__________________________________________________\n";
    cout << "Tong so tien luong phai tra: " << TotalSalary (List, m+n) << endl << endl;
    
    cout << "---------- Danh sach xuat thong tin nhan vien tang dan theo ngay sinh (lon tuoi truoc, nho tuoi sau) ----------\n";
    SortByDate (List, m+n, -1);
    Output (List, n+m);
    
    string sDate;
    cout << "Nhap ngay hien tai (VD: 25/02/2022): ";
    getline(cin, sDate);
    while (!(ValidDate (sDate))) {
        cout << "Ngay thang nam khong hop le !" << endl;
        cout << "Nhap ngay hien tai (VD: 25/02/2022): ";
        getline(cin, sDate);
    }
    cout << "---------- Danh sach nhan vien co ngay sinh nhat gan voi ngay hien tai ----------\n";
    ClosestDate (List, n+m, sDate).PrintFull();
    
    return 0;
}
