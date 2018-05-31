#include <iostream>

using std::cout;
using std::endl;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintTable(int* tableau, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << tableau[i] << " ";
	}
	cout << endl;
}

void Sort(int* tableau, int size)
{
	for (int start = 0; start < size - 1; start++)
	{
		for (int k = start + 1; k < size; k++)
		{
			if (tableau[k] < tableau[start])
			{
				Swap(&tableau[start], &tableau[k]);
			}
		}
	}
}

int main()
{
	int tableau[] = { 4, 6, 7, 12, 3 };
	int size = sizeof(tableau) / sizeof(int);

	PrintTable(tableau, size);
	Sort(tableau, size);
	PrintTable(tableau, size);

	system("pause");

	return 0;
}