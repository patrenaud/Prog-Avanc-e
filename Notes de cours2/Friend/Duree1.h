#pragma once
#include<ostream>

class Duree1
{
public:
	Duree1(int heure = 0, int minutes = 0, int secondes = 0);
	~Duree1();

	Duree1& operator+=(const Duree1& duree);

private:
	void Afficher(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream &out, Duree1 const& duree);
	friend Duree1 operator+(Duree1 const& a_Duree1, Duree1 const& a_Duree2);

	int m_Heures;
	int m_Minutes;
	int m_Secondes;
};


