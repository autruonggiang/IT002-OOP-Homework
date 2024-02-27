#pragma once

#include <string>
#include <iostream>
#include "Date.h"

enum TYPE {
	tOFFICE = 1,
	tPRODUCTION = 2
};

enum RATE {
	rOFFICE = 100000,
	rPRODUCTION = 5000
};

static int nowYear = -1;
class Employee
{
	std::string lName, fName, Name;
	float rate;
	float base;
	float efficiency;
	int type;
	Date date;

public:
	float const getRate() { return this->rate; }
	float const getBase() { return this->base; }
	float const getEfficiency() { return this->efficiency; }
	std::string const getFName() { return this->fName; }
	std::string const getLName() { return this->lName; }
	std::string const getName() { return this->Name; }
	int getAge();
	int getNowYear() { return nowYear; }
	Date* getDate() { return &date; }
	int getType() { return this->type; }

	void setRate(float rate) { this->rate = rate; }
	void setBase(float base) { this->base = base; }
	void setEfficiency(float efficiency) { this->efficiency = efficiency; }
	void setType(int type) { this->type = type; }
	void setName(std::string);
	void setNowYear(int now) { nowYear = now; }

	float const getSalary() { return base + efficiency * rate; }

	void Input();
	void Output();

};

