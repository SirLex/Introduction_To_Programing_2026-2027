/*
Задача 2: Въвеждат се две цели числа a и b. Да се разменят стойностите им и да се изведат.

Вход: 2005 2007, Изход: a = 2007
                        b = 2005
*/

#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int temp = a;
	a = b;
	b = temp;

	std::cout << "a = " << a << '\n';
	std::cout << "b = " << b << '\n';
}