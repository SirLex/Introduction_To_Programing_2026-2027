/*
	Задача 6
	Въвежда се цяло число N и квадратна матрица от цели числа с размери N × N. Да се провери дали всички
	елементи под второстепенния диагонал на матрицата са равни на 0. Да се изведе true, ако е така, и false в
	противен случай.

	Вход:
	4
	1 2 3 4
	5 6 7 0
	8 9 0 0
	1 0 0 0

	Изход:
	true

	Вход:
	3
	1 2 3
	4 5 0
	6 7 0

	Изход:
	false
*/

#include <iostream>

const int MAX_SIZE = 100;

void readMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

bool isZeroBelowSecondary(const int matrix[][MAX_SIZE], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = size - i; j < size; j++)
		{
			if (matrix[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int size;
	std::cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	readMatrix(matrix, size, size);

	std::cout << (isZeroBelowSecondary(matrix, size) ? "true" : "false");
}
