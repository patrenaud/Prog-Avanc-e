#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 10;
	int* p = &a;

	cout << "a est un int de taille: " << sizeof(a) << " octets" << endl;
	cout << " adresse de a: " << &a << endl;

	cout << "adresse suivante: " << ++p << endl;

	system("pause");
	return 0;
}