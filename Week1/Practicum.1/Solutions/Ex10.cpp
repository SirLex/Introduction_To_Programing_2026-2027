/*
Задача 10: Въвеждат се три реални числа. Да се изведе 1, ако сборът на първите две е равен на третото,
и 0 в противен случай. Задължително изпробвайте решението си с вход 0.1 0.2 0.3.

Вход: 1.5 2.5 4, Изход: 1

Вход: 0.1 0.2 0.3, Изход: 1
*/

#include <iostream>

int main()
{
	const double EPS = 1e-9;

	double a, b, c;
	std::cin >> a >> b >> c;

	double difference = (a + b) - c;

	bool isEqual = -EPS < difference && difference < EPS;

	std::cout << isEqual;
}