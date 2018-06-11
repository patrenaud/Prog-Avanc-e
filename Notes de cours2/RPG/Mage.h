#pragma once
#include "Characters.h"
class Mage :
	public Characters
{
public:
	Mage(const int a_Damage = 15, const int a_Hp = 5);
	virtual ~Mage();
};

