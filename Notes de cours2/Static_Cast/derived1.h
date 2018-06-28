#pragma once
#include <iostream>
#include "base.h"

class Derived1 : public Base
{
public:
	void ShowDerived1()
	{
		std::cout << "Derived1" << std::endl;
	}
};