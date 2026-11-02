/*
Задача 1: Въвеждат се две реални числа, като второто е различно от 0. Да се изведе най-голямата стойност, която
може да се
получи, ако с двете числа се извърши събиране, изваждане (първото минус второто), умножение или деление (първото на
второто).

Вход: 2 6, Изход: 12
*/

#include <iostream>

int main()
{
	const double EPS = 1e-9;

	double a, b;
	std::cin >> a >> b;

	// стойността се сменя само ако новата е по-голяма с повече от EPS
	double maxValue = a + b;
	maxValue = (a - b > maxValue + EPS) ? a - b : maxValue;
	maxValue = (a * b > maxValue + EPS) ? a * b : maxValue;
	maxValue = (a / b > maxValue + EPS) ? a / b : maxValue;

	std::cout << maxValue;
}