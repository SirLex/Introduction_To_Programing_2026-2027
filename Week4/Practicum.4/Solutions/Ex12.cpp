/*
Задача 12: Едно число е число на Армстронг, ако е равно на сбора от цифрите си, всяка повдигната на степен, равна
на броя на цифрите му. Напишете функция, която приема краищата на интервал [a, b] и извежда на екрана всички числа
на Армстронг в него.

Пример: 153 = 1^3 + 5^3 + 3^3

Вход: 100 500, Изход: 153 370 371 407
*/

#include <iostream>

int power(int base, int exp)
{
	int result = 1;

	for (int i = 0; i < exp; i++)
	{
		result *= base;
	}

	return result;
}

int countDigits(int number)
{
	int count = 0;

	do
	{
		count++;
		number /= 10;
	} while (number > 0);

	return count;
}

bool isArmstrong(int number)
{
	int digitsCount = countDigits(number);
	int sum = 0;

	for (int temp = number; temp > 0; temp /= 10)
	{
		sum += power(temp % 10, digitsCount);
	}

	return (sum == number);
}

void printArmstrongNumbers(int a, int b)
{
	bool isFirst = true;

	for (int number = a; number <= b; number++)
	{
		if (isArmstrong(number))
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

	printArmstrongNumbers(a, b);
}
