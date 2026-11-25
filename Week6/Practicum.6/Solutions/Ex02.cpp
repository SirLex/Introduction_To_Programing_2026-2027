/*
	Задача 2
	Да се изведе сумата на елементите на всеки ред на матрицата, всяка на нов ред.

	Вход:
	3 7
	7 8 7 4 1 1 0
	1 2 0 1 2 1 0
	7 5 2 1 0 1 0

	Изход:
	28
	7
	16
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

	for (int i = 0; i < rows; i++)
	{
		int rowSum = 0;
		for (int j = 0; j < cols; j++)
		{
			rowSum += matrix[i][j];
		}

		std::cout << rowSum << '\n';
	}
}
