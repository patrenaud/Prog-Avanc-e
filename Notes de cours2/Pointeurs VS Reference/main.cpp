#include <iostream>

using std::cout;
using std::endl;

void Pointeur();
void Reference();

int main()
{
	Pointeur();
	Reference();

	system("pause");
	return 0;
}

void Pointeur()
{
	cout << "Utilisation d'un pointeur" << endl << "--------------" << endl;
	int age = 21;
	int* pointeurSurAge = &age;

	cout << *pointeurSurAge << endl;
	*pointeurSurAge = 40;
	cout << *pointeurSurAge << endl;
}

void Reference()
{
	cout << "Utilisation d'une reference" << endl << "--------------" << endl;
	int age = 21;
	int &referenceSurAge = age;

	cout << referenceSurAge << endl;
	referenceSurAge = 40;
	cout << referenceSurAge << endl;
}