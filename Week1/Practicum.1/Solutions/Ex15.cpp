/*
Задача 15 (бонус): Въвеждат се три положителни (не непременно цели) числа – страни на триъгълник.
Да се изведат периметърът и лицето му. Приемете, че такъв триъгълник винаги съществува.

Вход: 3 4 5, Изход: Area = 6, Perimeter = 12
*/

#include <iostream>
#include <cmath>

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;

	double perimeter = a + b + c;

	double semiPerimeter = perimeter / 2;
	double area = std::sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));

	std::cout << "Area = " << area << ", Perimeter = " << perimeter;
}