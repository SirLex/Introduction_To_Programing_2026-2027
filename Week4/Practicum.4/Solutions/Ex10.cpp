/*
Задача 10: Напишете функция printByDigitAverage(int m, int n, int k), която извежда на екрана всички числа в
интервала [m, n] (0 < m < n <= 1000000), за които средноаритметичното на цифрите е по-голямо или равно на k (0 < k
< 10).

printByDigitAverage(10, 50, 6)  ->  39 48 49
*/

#include <iostream>

int sumDigits(int number)
{
	int sum = 0;

	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

int countDigits(int number)
{
	int count = 0;

	while (number > 0)
	{
		count++;
		number /= 10;
	}

	return count;
}

void printByDigitAverage(int m, int n, int k)
{
	bool isFirst = true;

	for (int number = m; number <= n; number++)
	{
		// средноаритметичното е >= k точно когато сборът е >= k * броя на цифрите;
		// така сравняваме цели числа и не делим
		if (sumDigits(number) >= k * countDigits(number))
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
	int m, n, k;
	std::cin >> m >> n >> k;

	printByDigitAverage(m, n, k);
}
