#pragma once
#include "Employee.h"

class Production : public Employee
{
public:
	Production() {
		this->setType(TYPE(tPRODUCTION));
		this->setRate(RATE(rPRODUCTION));
	};

	Production(std::string Name, std::string date, float Base, float numProducts) {
		this->setType(TYPE(tPRODUCTION));
		this->setRate(RATE(rPRODUCTION));

		this->setName(Name);
		this->getDate()->Input(date);
		this->setBase(Base);
		this->setEfficiency(numProducts);
	}
};
