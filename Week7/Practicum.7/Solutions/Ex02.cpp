/*
	Задача 2
	Въвеждат се цели числа N и M и матрица от цели числа с размери N × M. Да се провери дали в матрицата има
	елемент, чиято стойност е равна на произведението на номера на реда и номера на колоната, в които се
	намира (номерацията започва от 0). Да се изведе true, ако има такъв елемент, и false в противен случай.

	Вход:
	3 4
	2 3 99 84
	2 1 11 10
	2 5 33 -2

	Изход:
	true

	Вход:
	2 3
	5 1 7
	3 2 9

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

bool hasIndexProductElement(const int matrix[][MAX_SIZE], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == i * j)
			{
				return true;
			}
		}
	}

	return false;
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

	std::cout << (hasIndexProductElement(matrix, rows, cols) ? "true" : "false");
}
