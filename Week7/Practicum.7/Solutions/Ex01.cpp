/*
	Задача 1
	Въвеждат се цели числа N и M и матрица от цели числа с размери N × M. Да се изведе броят на отрицателните
	елементи във всеки ред на матрицата, като числата се разделят с интервал.

	Вход:
	4 4
	5 6 3 8
	2 4 3 -8
	1 6 0 8
	-2 -2 1 2

	Изход:
	0 1 0 2
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

int countNegatives(const int arr[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	if (rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE)
	{
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	readMatrix(matrix, rows, cols);

	// всеки ред matrix[i] е обикновен масив с cols елемента
	for (int i = 0; i < rows; i++)
	{
		std::cout << countNegatives(matrix[i], cols) << ' ';
	}
}
