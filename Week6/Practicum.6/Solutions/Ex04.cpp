/*
	Задача 4
	Въвежда се квадратна матрица. Да се провери дали всички елементи по главния диагонал са равни на 0.

	Вход:
	3
	0 5 2
	4 0 7
	1 3 0

	Изход:
	true

	Вход:
	3
	0 5 2
	4 6 7
	1 3 0

	Изход:
	false
*/

#include <iostream>

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

	bool isZeroDiagonal = true;
	for (int i = 0; i < size && isZeroDiagonal; i++)
	{
		if (matrix[i][i] != 0)
		{
			isZeroDiagonal = false;
		}
	}

	std::cout << (isZeroDiagonal ? "true" : "false");
}
