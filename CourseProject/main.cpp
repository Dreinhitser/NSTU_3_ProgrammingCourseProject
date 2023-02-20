#include "Fraction.hpp"
#include <iostream>

int main()
{
	// todo написать тесты
	Fraction f(11, 131);
	Fraction f2(47, 53);

	Fraction res;

	res = f + f2;

	res.display();

	return 0;
}