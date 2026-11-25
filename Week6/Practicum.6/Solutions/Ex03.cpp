/*
	Задача 3
	Да се изведе най-големият елемент във всяка колона на матрицата, разделени с интервал.

	Вход:
	3 4
	1 8 3 -2
	7 2 9 -5
	4 6 0 -1

	Изход:
	7 8 9 -1
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;

	int rows, cols;
	std::cin >> rows >> cols;

	if (rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE)
	{
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	for (int j = 0; j < cols; j++)
	{
		int maxElement = matrix[0][j];
		for (int i = 1; i < rows; i++)
		{
			if (matrix[i][j] > maxElement)
			{
				maxElement = matrix[i][j];
			}
		}

		std::cout << maxElement << ' ';
	}
}
