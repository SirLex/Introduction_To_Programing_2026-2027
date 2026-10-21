/*
Задача 11: Въвеждат се 4 реални числа a, b, c, d. Да се изведе 1, ако интервалите [a, b] и [c, d] се пресичат,
и 0 в противен случай.

Вход: 2 4 3 5, Изход: 1

Вход: 1 4 5 8, Изход: 0
*/

#include <iostream>

int main()
{
	double a, b, c, d;
	std::cin >> a >> b >> c >> d;

	bool intersect = a <= d && c <= b;

	std::cout << intersect;
}