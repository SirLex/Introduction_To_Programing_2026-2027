/*
Задача 12: Въвеждат се 4 цели числа. Да се изведе 1, ако в реда на въвеждане те образуват геометрична прогресия,
и 0 в противен случай.

Вход: 2 4 8 16, Изход: 1

Вход: 2 4 6 8, Изход: 0
*/

#include <iostream>

int main()
{
	long long a, b, c, d;
	std::cin >> a >> b >> c >> d;

	bool hasNoZeros = a != 0 && b != 0;
	bool hasGeometricProperty = b * b == a * c && c * c == b * d;

	bool isGeometric = hasNoZeros && hasGeometricProperty;

	std::cout << isGeometric;
}