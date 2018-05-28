#include "Duree1.h"



Duree1::Duree1(int heure, int minutes, int secondes)
	: m_Heures(heure)
	, m_Minutes(minutes)
	, m_Secondes(secondes)
{
}


Duree1::~Duree1()
{
}

void Duree1::Afficher(std::ostream& out) const
{
	out << m_Heures << "h" << m_Minutes << "m" << m_Secondes << "s";
}

Duree1& Duree1::operator+=(const Duree1& duree)
{
	m_Secondes += duree.m_Secondes;
	m_Minutes += m_Secondes / 60;
	m_Secondes %= 60;

	m_Minutes += duree.m_Minutes;
	m_Heures += m_Minutes / 60;
	m_Minutes %= 60;

	m_Heures += duree.m_Heures;

	return *this;
}


Duree1 operator+(Duree1 const& duree1, Duree1 const& duree2)
{
	Duree1 copie(duree1);

	copie += duree2;
	return copie;
}

std::ostream &operator<< (std::ostream &out, Duree1 const& duree)
{
	duree.Afficher(out);
	return out;
}
