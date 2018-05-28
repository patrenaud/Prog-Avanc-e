#pragma once
#include <ostream>

class Duree
{
public:
	Duree(int a_Heures = 0, int a_Minutes = 0, int a_Secondes = 0);
	~Duree();

	Duree& operator+=(const Duree& duree);

	void Afficher(std::ostream& out) const;

private:
	int m_Heures;
	int m_Minutes;
	int m_Secondes;
};

std::ostream& operator<< (std::ostream &out, Duree const& duree);

Duree operator+(Duree const& duree1, Duree const& duree2);



