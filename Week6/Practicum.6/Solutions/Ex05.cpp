/*
	Задача 5
	Въвежда се квадратна матрица от естествени числа. Да се провери дали в частта над главния диагонал
	на матрицата има просто число.

	Вход:
	3
	4 7 8
	10 6 9
	15 20 5

	Изход:
	true

	Вход:
	3
	1 4 6
	2 3 8
	5 7 9

	Изход:
	false
*/

#include <iostream>

bool isPrime(int number)
{
	if (number < 2)
	{
		return false;
	}

	for (int divisor = 2; divisor * divisor <= number; divisor++)
	{
		if (number % divisor == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	const int MAX_SIZE = 100;

	int size;
	std::cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	bool hasPrime = false;
	for (int i = 0; i < size && !hasPrime; i++)
	{
		for (int j = i + 1; j < size && !hasPrime; j++)
		{
			if (isPrime(matrix[i][j]))
			{
				hasPrime = true;
			}
		}
	}

	std::cout << (hasPrime ? "true" : "false");
}
