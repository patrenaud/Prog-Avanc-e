#include <iostream>
#include "Duree.h"

using std::cout;
using std::endl;

int main()
{
	Duree duree1(0, 10, 42);

	Duree duree2(2, 53, 27);
	cout << duree1 << " + " << duree2 << " = " << duree1 + duree2 << endl;
	cout << duree1;

	system("pause");

	return 0;
}