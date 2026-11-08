/*
Задача 8: Напишете функция findMinMaxDigit, която приема неотрицателно цяло число и намира най-малката и
най-голямата му цифра.

Вход: 50291, Изход: 0 9

Вход: 7, Изход: 7 7
*/

#include <iostream>

// една функция не може да върне две стойности с return,
// затова резултатите се записват в параметрите, подадени по референция
void findMinMaxDigit(unsigned int n, int& minDigit, int& maxDigit)
{
	minDigit = n % 10;
	maxDigit = n % 10;
	n /= 10;

	while (n > 0)
	{
		int digit = n % 10;

		if (digit < minDigit)
		{
			minDigit = digit;
		}
		if (digit > maxDigit)
		{
			maxDigit = digit;
		}

		n /= 10;
	}
}

int main()
{
	unsigned int n;
	std::cin >> n;

	int minDigit, maxDigit;
	findMinMaxDigit(n, minDigit, maxDigit);

	std::cout << minDigit << ' ' << maxDigit;
}