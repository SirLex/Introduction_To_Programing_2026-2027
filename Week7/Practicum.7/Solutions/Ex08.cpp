/*
	Задача 8
	Напишете функция, която отпечатва елементите на матрица N x M по диагоналите, успоредни на
	второстепенния: всеки диагонал на отделен ред, като всеки се обхожда отдолу-наляво нагоре-надясно.

	Вход:
	5 4
	1 2 3 4
	5 6 7 8
	9 10 11 12
	13 14 15 16
	17 18 19 20

	Изход:
	1
	5 2
	9 6 3
	13 10 7 4
	17 14 11 8
	18 15 12
	19 16
	20
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

void printSecondaryDiagonals(const int matrix[][MAX_SIZE], int rows, int cols)
{
	// по всеки диагонал, успореден на второстепенния, сборът i + j е постоянен
	for (int sum = 0; sum <= rows + cols - 2; sum++)
	{
		// започваме от най-долния елемент на диагонала
		int i = (sum < rows) ? sum : rows - 1;
		int j = sum - i;

		while (i >= 0 && j < cols)
		{
			std::cout << matrix[i][j] << ' ';
			i--;
			j++;
		}
		std::cout << '\n';
	}
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

	printSecondaryDiagonals(matrix, rows, cols);
}
