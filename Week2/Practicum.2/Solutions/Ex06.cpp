/*
Задача 6: Въвеждат се координатите на долния ляв и след това на горния десен връх на правоъгълник, чиито страни
са успоредни на координатните оси. След това се въвеждат координатите на трета точка. Всички координати са
реални числа. Да се изведе Inside, ако точката е вътре в правоъгълника, On the border, ако е върху някоя от
страните му, и Outside, ако е извън него.

Вход: 1 1 5 4
      3 2,     Изход: Inside

Вход: 1 1 5 4
      5 2.5,   Изход: On the border

Вход: 0 0 2 2
      3 1,     Изход: Outside
*/

#include <iostream>

int main()
{
	const double EPS = 1e-9;

	double left, bottom, right, top;
	std::cin >> left >> bottom >> right >> top;

	double x, y;
	std::cin >> x >> y;

	bool isOutside = (x < left - EPS || x > right + EPS || y < bottom - EPS || y > top + EPS);
	bool isInside = (x > left + EPS && x < right - EPS && y > bottom + EPS && y < top - EPS);

	if (isOutside)
	{
		std::cout << "Outside";
	}
	else if (isInside)
	{
		std::cout << "Inside";
	}
	else
	{
		std::cout << "On the border";
	}
}
