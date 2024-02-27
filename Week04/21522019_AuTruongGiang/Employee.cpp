#include "Employee.h"
#include <limits>

void Employee::setName(std::string sName) {
	this->Name = sName;

	std::string temp = "";
	for (int i = 0; sName[i] != ' '; ++i) {
		temp += sName[i];
	}

	this->fName = temp;

	temp = "";
	for (int i = sName.length() - 1; sName[i] != ' '; --i) {
		temp += sName[i];
	}

	this->lName = temp;
}

void Employee::Input() {

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Nhap ho ten: ";
	std::getline(std::cin, this->Name);

	std::string sInputDate;
	std::cout << "Nhap ngay thang nam sinh (VD: 01/01/2000): ";
	std::getline(std::cin, sInputDate);

	while (!(this->getDate()->ValidDate(sInputDate))) {
		std::cout << "Ngay thang nam sinh khong hop le !" << std::endl;
		std::cout << "Nhap ngay thang nam sinh (VD: 01/01/2000): ";
		std::getline(std::cin, sInputDate);
	}

	this->getDate()->Input(sInputDate);

	if (type == TYPE(tPRODUCTION)) {
		std::cout << "Nhap luong co ban: ";
		std::cin >> base;
		std::cout << "Nhap so san pham: ";
		std::cin >> efficiency;
	}
	else {
		std::cout << "Nhap so ngay lam viec: ";
		std::cin >> efficiency;
	}
}

void Employee::Output() {
	std::cout << "Ho va ten: " << this->Name << std::endl;
	std::cout << "Ngay thang nam sinh: ";
	this->getDate()->Output();

	if (type == TYPE(tPRODUCTION)) {
		std::cout << "Nhan vien san xuat" << std::endl;
		std::cout << "Luong co ban: " << base << std::endl;
		std::cout << "So san pham: " << efficiency << std::endl;
	}
	else {
		std::cout << "Nhan vien van phong" << std::endl;
		std::cout << "So ngay lam viec: " << efficiency << std::endl;
	}
}

int Employee::getAge() {
	if (nowYear <= 0) {
		std::cout << "Nhap nam hien tai: ";
		std::cin >> nowYear;
	}

	return nowYear - this->getDate()->getYear();
}