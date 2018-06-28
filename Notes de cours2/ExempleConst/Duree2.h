#pragma once
#include <iostream>


class Duree2
{
public:
	explicit Duree2(int heures = 0, int minutes = 0, int secondes = 0)
		: m_Time(heures * 3600 + minutes * 60 + secondes)
	{

	}
	void Afficher() const
	{
		//m_Time = 0; // Impossible car fonction est const

		std::cout << m_Time / 3600 << "h" << m_Time % 3600 / 60 << "m" << m_Time % 60 << "s" << std::endl;
	}

private :
	unsigned int m_Time;
};

