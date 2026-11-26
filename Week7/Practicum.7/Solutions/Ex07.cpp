/*
	Задача 7
	Въвеждат се цели числа N и M, матрица от цели числа с размери N × M и цели числа P и Q (1 ≤ P ≤ N, 1 ≤ Q
	≤ M). Подматрица с размери P × Q се състои от P последователни реда и Q последователни колони на
	матрицата. Да се изведе най-голямата сума на елементите на подматрица с размери P × Q.

	Вход:
	4 6
	1 2 3 4 5 6
	4 5 -1 6 7 8
	-1 3 9 10 19 3
	0 4 5 8 -13 2
	2 3

	Изход:
	53
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

int submatrixSum(const int matrix[][MAX_SIZE], int top, int left, int p, int q)
{
	int sum = 0;
	for (int i = top; i < top + p; i++)
	{
		for (int j = left; j < left + q; j++)
		{
			sum += matrix[i][j];
		}
	}

	return sum;
}

int maxSubmatrixSum(const int matrix[][MAX_SIZE], int rows, int cols, int p, int q)
{
	int maxSum = submatrixSum(matrix, 0, 0, p, q);

	for (int top = 0; top <= rows - p; top++)
	{
		for (int left = 0; left <= cols - q; left++)
		{
			int sum = submatrixSum(matrix, top, left, p, q);
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	return maxSum;
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

	int p, q;
	std::cin >> p >> q;

	if (p < 1 || p > rows || q < 1 || q > cols)
	{
		return 1;
	}

	std::cout << maxSubmatrixSum(matrix, rows, cols, p, q);
}
