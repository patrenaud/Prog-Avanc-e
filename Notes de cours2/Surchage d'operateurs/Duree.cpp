#include "Duree.h"



Duree::Duree(int a_Heures, int a_Minutes, int a_Secondes)
	:m_Heures(a_Heures)
	, m_Minutes(a_Minutes)
	, m_Secondes(a_Secondes)
{
}

Duree::~Duree()
{
}

void Duree::Afficher(std::ostream& out) const
{
	out << m_Heures << "h" << m_Minutes << "m" << m_Secondes << "s";
}

Duree& Duree::operator+=(const Duree& duree)
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


Duree operator+(Duree const& duree1, Duree const& duree2)
{
	Duree copie(duree1);

	copie += duree2;
	return copie;
}

std::ostream &operator<< (std::ostream &out, Duree const& duree)
{
	duree.Afficher(out);
	return out;
}

