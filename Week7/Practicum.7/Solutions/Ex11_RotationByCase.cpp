/*
	Задача 11
	Въвеждат се цели числа N и M, матрица от цели числа с размери N × M и цяло число deg, което се дели на
	90. Да се изведе матрицата, завъртяна на deg градуса. Ако deg е положително, матрицата се завърта по
	посока на часовниковата стрелка, а ако е отрицателно – обратно на нея.

	Вход:
	2 3
	1 2 3
	4 5 6
	90

	Изход:
	4 1
	5 2
	6 3

	Вход:
	2 3
	1 2 3
	4 5 6
	180

	Изход:
	6 5 4
	3 2 1

	Вход:
	2 4
	1 2 3 4
	5 6 7 8
	720

	Изход:
	1 2 3 4
	5 6 7 8

	Вход:
	3 3
	1 2 3
	4 5 6
	7 8 9
	-450

	Изход:
	3 6 9
	2 5 8
	1 4 7
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

void printMatrix(const int matrix[][MAX_SIZE], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void copyMatrix(const int source[][MAX_SIZE], int destination[][MAX_SIZE], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			destination[i][j] = source[i][j];
		}
	}
}

void swapSizes(int& rows, int& cols)
{
	int temp = rows;
	rows = cols;
	cols = temp;
}

void rotate90(int matrix[][MAX_SIZE], int& rows, int& cols)
{
	int rotated[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rotated[j][rows - 1 - i] = matrix[i][j];
		}
	}

	swapSizes(rows, cols);
	copyMatrix(rotated, matrix, rows, cols);
}

void rotate180(int matrix[][MAX_SIZE], int rows, int cols)
{
	int rotated[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rotated[rows - 1 - i][cols - 1 - j] = matrix[i][j];
		}
	}

	copyMatrix(rotated, matrix, rows, cols);
}

void rotate270(int matrix[][MAX_SIZE], int& rows, int& cols)
{
	int rotated[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rotated[cols - 1 - j][i] = matrix[i][j];
		}
	}

	swapSizes(rows, cols);
	copyMatrix(rotated, matrix, rows, cols);
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

	int deg;
	std::cin >> deg;

	if (deg % 90 != 0)
	{
		return 1;
	}

	// всяко завъртане е еквивалентно на 0, 1, 2 или 3 завъртания на 90 градуса по часовниковата стрелка
	int turns = (deg / 90) % 4;
	if (turns < 0)
	{
		turns += 4;
	}

	switch (turns)
	{
	case 1:
		rotate90(matrix, rows, cols);
		break;
	case 2:
		rotate180(matrix, rows, cols);
		break;
	case 3:
		rotate270(matrix, rows, cols);
		break;
	}

	printMatrix(matrix, rows, cols);
}
