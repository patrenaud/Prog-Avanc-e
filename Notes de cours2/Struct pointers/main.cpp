#include <iostream>

using std::cout;
using std::endl;

struct ABC
{
	int a;
	int b;
	int c;
};

void ChangerValeurs(ABC* p, int valeur)
{
	p->a = valeur - 1;
	(*p).b = valeur;
	p->c = valeur + 1;
}

int main()
{
	ABC MaStruct;
	ChangerValeurs(&MaStruct, 10);

	cout << "valeurs";
	cout << " a =  " << MaStruct.a;
	cout << " b =  " << MaStruct.b;
	cout << " c =  " << MaStruct.c;

	cout << endl;

	system("pause");

	return 0;
}