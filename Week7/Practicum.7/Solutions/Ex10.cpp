/*
	Задача 10
	Въвеждат се цели числа N и M и матрица от цели числа с размери N × M. Да се изведат елементите на
	матрицата спираловидно – отвън навътре, по посока на часовниковата стрелка, като се започне от горния ляв
	ъгъл.

	Вход:
	3 4
	1 2 3 4
	5 6 7 8
	9 10 11 12

	Изход:
	1 2 3 4 8 12 11 10 9 5 6 7
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

void printSpiral(const int matrix[][MAX_SIZE], int rows, int cols)
{
	int top = 0;
	int bottom = rows - 1;
	int left = 0;
	int right = cols - 1;

	while (top <= bottom && left <= right)
	{
		// горен ред отляво надясно
		for (int j = left; j <= right; j++)
		{
			std::cout << matrix[top][j] << ' ';
		}
		top++;

		// дясна колона отгоре надолу
		for (int i = top; i <= bottom; i++)
		{
			std::cout << matrix[i][right] << ' ';
		}
		right--;

		// долен ред отдясно наляво, ако все още има такъв
		if (top <= bottom)
		{
			for (int j = right; j >= left; j--)
			{
				std::cout << matrix[bottom][j] << ' ';
			}
			bottom--;
		}

		// лява колона отдолу нагоре, ако все още има такава
		if (left <= right)
		{
			for (int i = bottom; i >= top; i--)
			{
				std::cout << matrix[i][left] << ' ';
			}
			left++;
		}
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

	printSpiral(matrix, rows, cols);
}
