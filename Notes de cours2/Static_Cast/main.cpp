#include "base.h"
#include "derived1.h"
#include "derived2.h"

int main()
{
	Base* base = new Derived1();

	Derived1* derived1 = static_cast<Derived1*>(base); // Cette ligne est correcte
	Derived2* derived2 = static_cast<Derived2*>(base); // N'est pas bien 
	
	derived1->ShowDerived1();
	derived2->ShowDerived2();

	system("pause");
	return 0;
}