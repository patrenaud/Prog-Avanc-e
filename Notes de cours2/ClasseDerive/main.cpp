#include "StorageBoxx.h"

int main()
{
	StorageBoxx* sb = new StorageBoxx(1, 2, 3, "Boxx1");
	delete sb;
	system("pause");
	return 0;
}