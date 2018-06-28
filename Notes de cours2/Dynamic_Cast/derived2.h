#pragma once
#include <iostream>
#include "base.h"

class Derived2 : public base
{
public:
	void ShowDerived2()
	{
		std::cout << "Derived2" << std::endl;
	}
};

