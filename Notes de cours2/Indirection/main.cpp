#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int a = 5;
	int b = 2;
	int c = 17;
	int* p = nullptr;

	p = &a;
	cout << "Adresse de a " << p << endl;
	cout << "p pointe sur a: " << *p << endl;
	cout << "p pointe sur a: " << *(&a) << endl;

	p = &b;
	cout << "p pointe sur b: " << *p << endl;

	system("pause");

}