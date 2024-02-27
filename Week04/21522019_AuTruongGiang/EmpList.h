#pragma once
#include "Employee.h"
#include <iostream>

class EmpList
{
	int size = 0;
	Employee* List;
	int type;

public:

	~EmpList() {
		delete[] List;
	}

	int const getSize() { return size; }

	void setType(int type) { this->type = type; }

	void Input();
	void Output();

	float getArgAge();
	float getTotalAge();
	Employee* getMaxAge();
	Employee* getMinAge();

	float getArgSalary();
	int getTotalSalary();
	Employee* getMaxSalary();
	Employee* getMinSalary();

	Employee* getList() { return this->List; }

};
