#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a;
	int b;
	int c;

	cout << "Taille d'un int: " << sizeof(int) << " octets" << endl;
	cout << "Taille d'un char: " << sizeof(char) << " octets" << endl;
	cout << "Taills d'un std::string " << sizeof(std::string) << endl;

	std::string test = "Test";
	cout << "Taille de la variable test " << sizeof(test) << endl;

	cout << "Adresses de a: " << &a << endl;
	cout << "Adresses de b: " << &b << endl;
	cout << "Adresses de c: " << &c << endl;

	system("pause");

	return 0;
}