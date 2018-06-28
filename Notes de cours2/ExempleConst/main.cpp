#include "Duree2.h"

void ShowTime(const Duree2& duree);

int main()
{
	Duree2 duree(1, 5);
		ShowTime(duree);

	system("pause");
	return 0;
}


void ShowTime(const Duree2& duree)
{
	duree.Afficher();
}