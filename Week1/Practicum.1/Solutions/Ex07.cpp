/*
Задача 7: Въвеждат се 3 цели числа. Да се изведе 1, ако поне едно от тях е отрицателно, и 0 в противен случай.

Вход: 5 8 -21, Изход: 1

Вход: 4 2 6, Изход: 0
*/

#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	bool hasNegative = a < 0 || b < 0 || c < 0;

	std::cout << hasNegative;
}