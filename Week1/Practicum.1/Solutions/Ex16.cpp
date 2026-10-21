/*
Задача 16 (бонус): Да се въведат две числа a и b. Да се изведе по-голямото от двете, без да се използва if.

Вход: 265 44, Изход: 265

Вход: 3 8, Изход: 8
*/

#include <iostream>
#include <cmath>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int maxNumber = (a + b + std::abs(a - b)) / 2;

	std::cout << maxNumber;
}