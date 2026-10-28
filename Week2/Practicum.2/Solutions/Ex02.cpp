/*
Задача 2: Въвеждат се две цели числа. Да се изведе по-голямото от тях.

Вход: 265 44, Изход: 265

Вход: 3 8, Изход: 8
*/

#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	if (a > b)
	{
		std::cout << a;
	}
	else
	{
		std::cout << b;
	}
}
