#pragma once
#include "Employee.h"

class Office : public Employee 
{
public:
	Office() {
		this->setType(TYPE(tOFFICE));
		this->setRate(RATE(rOFFICE));
		this->setBase(0);
	};
	
	Office(std::string Name, std::string date, float dayWorks) {
		this->setType(TYPE(tOFFICE));
		this->setRate(RATE(rOFFICE));

		this->setName(Name);
		this->getDate()->Input(date);
		this->setBase(0);
		this->setEfficiency(dayWorks);
	}
};

