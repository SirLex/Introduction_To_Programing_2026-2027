/*
Задача 14 (бонус): Да се въведат координатите (x1, y1) и (x2, y2) на два срещуположни върха на правоъгълник.
Да се изчисли лицето на правоъгълника.

Вход: 1 1 4 5, Изход: 12
*/

#include <iostream>
#include <cmath>

int main()
{
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	double width = std::abs(x2 - x1);
	double height = std::abs(y2 - y1);

	double area = width * height;

	std::cout << area;
}