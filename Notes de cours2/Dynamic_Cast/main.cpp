#include "base.h"
#include "derived1.h"
#include "derived2.h"

int main()
{
	base* Base = new Derived1();

	Derived1* derived1 = dynamic_cast<Derived1*>(Base);

	Derived2* derived2 = dynamic_cast<Derived2*>(Base);

	Derived2& derived2_ref = dynamic_cast<Derived2&>(*Base);

	return 0;
}