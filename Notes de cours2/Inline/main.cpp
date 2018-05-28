#include <iostream>

inline int carre(int nombre);


int main()
{
	std::cout << carre(10) << std::endl;
	system("pause");
	return 0;
}

inline int carre(int nombre)
{
	return nombre * nombre;
}