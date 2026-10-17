/*
Задача 6: Да се напише програма, която приема 3 цели числа a, b, x.
Да се изведе 1, ако x е в интервала (a, b), и 0, ако не е.

Вход: 1 10 5, Изход: 1

Вход: 100 101 101, Изход: 0
*/

#include <iostream>

int main()
{
	int a, b, x;
	std::cin >> a >> b >> x;

	bool isInInterval = a < x && x < b;

	std::cout << isInInterval;
}