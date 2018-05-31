#include <iostream>

using std::cout;
using std::endl;

void AfficherTableau(int* i);

int main()
{
	int tableau1[10] = { 4, 6, 9, 45, 32, 1, 2, 3, 4, 0 };
	int tableau2[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,0 };

	int* t1 = tableau1;
	int* t2 = tableau2;

	AfficherTableau(tableau2);

	while (*t2++ = *t1++);

	AfficherTableau(tableau2);

	system("pause");

	return 0;
}

void AfficherTableau(int* t)
{
	while (*t)
	{
		cout << *t++ << " ";
	}
	cout << endl;
}