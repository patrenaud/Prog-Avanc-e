#include <iostream>


int main()
{
	int var = 10;
	std::cout << "Adresse mem de var" << &var << std::endl;

	int i;
	std::cout << "Adresse:  ";
	std::cin >> std::hex >> i >> std::dec;

	std::cout << "Contenu: " << *(reinterpret_cast<int*>(i)) << std::endl;

	system("pause");

	return 0;
}