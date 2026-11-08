/*
Задача 4: Напишете функция myPow(double base, int exp), която връща base на степен exp. Ако exp е отрицателно,
резултатът е реципрочен: 1 / base^|exp|. Приемете, че при отрицателно exp основата base е различна от 0.

myPow(2, 3)   ->  8
myPow(2, -2)  ->  0.25
myPow(5, 0)   ->  1
*/

#include <iostream>

double myPow(double base, int exp)
{
	int positiveExp = (exp < 0) ? -exp : exp;

	double result = 1;
	for (int i = 0; i < positiveExp; i++)
	{
		result *= base;
	}

	return (exp < 0) ? 1 / result : result;
}

int main()
{
	double base;
	int exp;
	std::cin >> base >> exp;

	std::cout << myPow(base, exp);
}
