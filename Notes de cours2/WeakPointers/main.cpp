#include <iostream>
#include <memory>

using std::shared_ptr;
using std::weak_ptr;
using std::cout;
using std::endl;

class A;
class B;

class A
{
public: weak_ptr<B> myB;

};

class B
{
public:
	weak_ptr<A> myA;

	void Function1()
	{
		cout << "Class B" << endl;
	}
};

int main()
{
	shared_ptr<A> a = std::make_shared<A>();
	shared_ptr<B> b = std::make_shared<B>();

	cout << a.use_count() << " , " << b.use_count() << endl;
	a->myB = b;
	cout << a.use_count() << " , " << b.use_count() << endl;
	b->myA = a;
	cout << a.use_count() << " , " << b.use_count() << endl;

	// Ces 2 lignes sont identiques
	b->Function1();
	a->myB.lock()->Function1();

	cout << a.use_count() << " , " << b.use_count() << endl;

	/*shared_ptr<B> myB(a->myB);
	myB->Function1;
	myB.reset*/  // Ces lignes fonctionnent aussi

	b.reset();

	if (a->myB.lock() ==  nullptr)
	{
		cout << "Nullptr " << endl;
	}

	a.reset();

	system("pause");
	return 0;
}