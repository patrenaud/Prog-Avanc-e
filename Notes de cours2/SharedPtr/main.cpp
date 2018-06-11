#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

void fonction1(const shared_ptr<int> a);

int main()
{
	shared_ptr<int> a(new int(420));
	cout << a.use_count() << endl;

	shared_ptr<int> b = a;
	cout << a.use_count() << endl;
	cout << b.use_count() << endl;
	// les 2 ont le même count car ils pointent vers la même chose.

	fonction1(a);

	// On affiche encore 2 ici car les pointeurs de la fonctions sont locales.
	cout << a.use_count() << endl;
	
	b.reset();
	b = nullptr;

	system("pause");
	return 0;
}

void fonction1(const shared_ptr<int> a) // le fait qu'on envoie pas de référence, on crée une copie donc un total de 4 pour le count
{	// Si on met a en référence, on ne pourra pas changer vers ce qu'il pointe
	shared_ptr<int> c;
	shared_ptr<int> d = make_shared<int>(56);

	c = a;
	cout << a.use_count() << endl;

	d = c;
	cout << a.use_count() << endl;
}