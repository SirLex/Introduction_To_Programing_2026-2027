/*
Задача 11: Напишете функция, която приема краищата на интервал [a, b] и извежда на екрана всички числа в него,
които са равни на сбора от факториелите на цифрите си.

Пример: 145 = 1! + 4! + 5!

Вход: 1 200, Изход: 1 2 145
*/

#include <iostream>

int factorial(int n)
{
	int result = 1;

	for (int i = 2; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

int sumOfDigitFactorials(int number)
{
	int sum = 0;

	do
	{
		sum += factorial(number % 10);
		number /= 10;
	} while (number > 0);

	return sum;
}

bool isStrong(int number)
{
	return (sumOfDigitFactorials(number) == number);
}

void printStrongNumbers(int a, int b)
{
	bool isFirst = true;

	for (int number = a; number <= b; number++)
	{
		if (isStrong(number))
		{
			if (!isFirst)
			{
				std::cout << ' ';
			}
			std::cout << number;
			isFirst = false;
		}
	}
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	printStrongNumbers(a, b);
}
