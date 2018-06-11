#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;
using std::make_shared;

class A;
class B;

class A
{
public:
	shared_ptr<B> myB;
};

class B
{
public:
	shared_ptr<A> myA;
};

int main()
{
	shared_ptr<A> a = make_shared<A>();
	shared_ptr<B> b = make_shared<B>();

	cout << a.use_count() << " , " << b.use_count << endl;

	a->myB = b;
	cout << a.use_count() << " , " << b.use_count << endl;

	b->myA = a;
	cout << a.use_count() << " , " << b.use_count << endl;

	// Dans cette situation, myA et myB ne sont pas détruits donc l'object du pointeur ne sera pas détruit (le compte reste à 1 - 1 )

	a.reset();
	a = nullptr;

	cout << b.use_count << endl;

	b.reset();
	b = nullptr;

	system("pause");


}