#pragma once

#include "EmpList.h"

class OfficeList : public EmpList
{
public:
	OfficeList() {
		this->setType(TYPE::tOFFICE);
	}
};

