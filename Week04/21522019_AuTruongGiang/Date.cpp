#include "Date.h"

using namespace std;

bool Date::CanStoi(string s) {
    string temp;
    for (long unsigned int i = 0; i < s.length(); ++i) {
        temp = "";
        temp += s[i];
        if (to_string(s[i] - '0') != temp)
            return false;
    }

    return true;
}

bool Date::ValidDate(string sDate) {
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
        }
        else {
            temp += sDate[i];
        }
    }

    if (check != 3)
        return false;

    if (num[0] < 1 || num[1] > 12 || num[1] < 0 || num[2] < 0)
        return false;

    if (num[1] == 2) {
        if (num[2] % 4 == 0) {
            if (num[0] > 29)
                return false;
        }
        else {
            if (num[0] > 28)
                return false;
        }
    }

    if (num[1] == 4 || num[1] == 6 || num[1] == 9) {
        if (num[0] > 30)
            return false;
    }
    else {
        if (num[0] > 31)
            return false;
    }

    return true;
}

void Date::Input(string sDate) {
    sDate += "/";

    string temp = "";
    int num[3];

    int check = 0;
    for (long unsigned int i = 0; i < sDate.length(); ++i) {
        if (sDate[i] == '/') {
            num[check] = stoi(temp);
            check++;
            temp = "";
        }
        else {
            temp += sDate[i];
        }
    }

    this->iDay = num[0];
    this->iMonth = num[1];
    this->iYear = num[2];
}

void Date::Output() {
    PrintFixNum(this->iDay);
    cout << "/";
    PrintFixNum(this->iMonth);
    cout << "/" << this->iYear << endl;
}

bool Date::Bigger(Date new_Date) {
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

bool Date::operator == (Date new_Date) {

    if (this->iYear == new_Date.iYear &&
        this->iMonth == new_Date.iMonth &&
        this->iDay == new_Date.iDay)
        return true;
    else
        return false;
}
