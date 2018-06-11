#pragma once
#include "Characters.h"
class Warrior :
	public Characters
{
public:
	Warrior(const int a_Damage = 5, const int a_Hp = 40);

	virtual ~Warrior();
};

