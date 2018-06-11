#include <iostream>

using std::cout;
using std::endl;

struct Coordonnees // Mesure 8 Octets
{
	int x;
	int y;
};

void RemiseAZero(Coordonnees& a_PointAModifier); // Mesure 4 Octets

int main()
{
	Coordonnees *point = new Coordonnees();
	point -> x = 5;
	point -> y = 10;

	cout << "x: " << point->x << " y: " << point->y << endl;
	RemiseAZero(*point);
	cout << "x: " << point->x << " y: " << point->y << endl;

	system("pause");
	return 0;
}

void RemiseAZero(Coordonnees& a_PointAModifier)
{
	a_PointAModifier.x = 0;
	a_PointAModifier.y = 0;
}