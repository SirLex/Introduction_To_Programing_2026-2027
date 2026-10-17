/*
Задача 13 (бонус): Да се напише програма, която прочита координатите на две точки и намира разстоянието между тях.

Вход: 0 0 3 4, Изход: 5
*/

#include <iostream>
#include <cmath>

int main()
{
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	double dx = x2 - x1;
	double dy = y2 - y1;

	double distance = std::sqrt(dx * dx + dy * dy);

	std::cout << distance;
}