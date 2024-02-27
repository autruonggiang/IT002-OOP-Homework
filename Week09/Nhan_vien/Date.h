#pragma once

#include <string>
#include <iostream>

class Date {

    int iDay, iMonth, iYear;

public:

    int const getYear() { return iYear; }
    int const getMonth() { return iMonth; }
    int const getDay() { return iDay; }

    bool CanStoi(std::string);
    bool ValidDate(std::string);

    void Input(std::string);

    void PrintFixNum(int num) {
        if (num < 10)
            std::cout << "0" << num;
        else
            std::cout << num;
    }

    void Output();

    bool Bigger(Date);

    bool operator > (Date new_Date) {
        return (!Bigger(new_Date));
    }

    bool operator < (Date new_Date) {
        return Bigger(new_Date);
    }

    bool operator == (Date new_Date);

};
