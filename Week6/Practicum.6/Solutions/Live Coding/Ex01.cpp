/*
	Задача 1
	Да се изведе най-малкият елемент на матрицата.

	Вход:
	3 4
	1 2 3 5
	4 5 6 5
	7 8 9 5

	Изход:
	1
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

	int minElement = matrix[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] < minElement)
			{
				minElement = matrix[i][j];
			}
		}
	}

	std::cout << minElement;
}
