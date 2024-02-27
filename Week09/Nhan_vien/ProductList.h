#pragma once

#include "EmpList.h"

class ProductList : public EmpList
{
public:
	ProductList() {
		this->setType(TYPE::tPRODUCTION);
	}
};

