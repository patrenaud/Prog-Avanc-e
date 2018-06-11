#include "Characters.h"



Characters::Characters(const int a_Damage, const int a_Hp)
	: m_Stats(new Stats(a_Damage, a_Hp))
{

}


Characters::~Characters()
{
	if (m_Stats != nullptr)
	{
		delete m_Stats;
		m_Stats = nullptr;
	}
}
