#include "EmpList.h"
#include "Office.h"
#include "Production.h"

void EmpList::Input() {

	do {
		std::cout << "Nhap so luong nhan vien : ";
		if (type == TYPE::tOFFICE) {
			std::cout << "van phong: ";
		}
		else {
			std::cout << "san xuat: ";
		}

		std::cin >> size;

	} while (size <= 0);

	if (type == TYPE::tOFFICE)
		List = new Office[size];
	else
		List = new Production[size];

	for (int i = 0; i < size; ++i) {
		List[i].Input();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void EmpList::Output() {
	for (int i = 0; i < size; ++i) {
		std::cout << "Nhan vien " << i + 1 << std::endl;
		List[i].Output();
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

float EmpList::getArgAge() {
	float sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += List[i].getAge();
	}

	return sum / size;
}

float EmpList::getTotalAge() {
	float sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += List[i].getAge();
	}

	return sum;
}


Employee* EmpList::getMaxAge() {
	int max = List[0].getAge();
	Employee* temp = &List[0];

	for (int i = 1; i < size; ++i) {
		if (List[i].getAge() > max) {

			max = List[i].getAge();
			temp = &List[i];
		}
	}

	return temp;
}

Employee* EmpList::getMinAge() {
	int min = List[0].getAge();
	Employee* temp = &List[0];

	for (int i = 1; i < size; ++i) {
		if (List[i].getAge() < min) {
			min = List[i].getAge();
			temp = &List[i];
		}
	}

	return temp;
}

float EmpList::getArgSalary() {
	float sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += List[i].getSalary();
	}

	return sum / size;
}

int EmpList::getTotalSalary() {
	int sum = 0;

	for (int i = 0; i < size; ++i) {
		sum += List[i].getSalary();
	}

	return sum;
}

Employee* EmpList::getMaxSalary() {
	int max = List[0].getSalary();
	Employee* temp = &List[0];

	for (int i = 0; i < size; ++i) {
		if (List[i].getSalary() > max) {
			max = List[i].getSalary();
			temp = &List[i];
		}
	}

	return temp;
}

Employee* EmpList::getMinSalary() {
	float min = List[0].getSalary();
	Employee* temp = &List[0];

	for (int i = 1; i < size; ++i) {
		if (List[i].getSalary() < min) {
			min = List[i].getSalary();
			temp = &List[i];
		}
	}

	return temp;
}