#include "D.h"
#include <iostream>

int main()
{

	std::cout << D::m_entierStatic << std::endl;

	D* d = new D();
	D* d2 = new D();
	D* d3 = new D();
	D* d4 = new D();
	D* d5 = new D();

	std::cout << D::m_entierStatic << std::endl;

	delete d;
	std::cout << D::m_entierStatic << std::endl;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	std::cout << D::m_entierStatic << std::endl;

	system("pause");
	return 0;
}