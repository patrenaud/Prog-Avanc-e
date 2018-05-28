#include <iostream>
#include "Duree1.h"

using std::cout;
using std::endl;

int main()
{
	Duree1 duree1(0, 10, 42);

	Duree1 duree2(2, 53, 27);
	cout << duree1 << " + " << duree2 << " = " << duree1 + duree2 << endl;
	cout << duree1;

	system("pause");

	return 0;
}