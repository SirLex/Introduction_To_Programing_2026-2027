/*
	Задача 3
	Въвежда се цяло число N и квадратна матрица от цели числа с размери N × N. Да се изведе сумата на
	елементите по главния и по второстепенния диагонал на матрицата. Ако N е нечетно, централният елемент на
	матрицата се брои само веднъж.

	Вход:
	3
	2 5 4
	6 8 7
	1 3 9

	Изход:
	24

	Вход:
	4
	1 2 3 4
	5 6 7 8
	9 10 11 12
	13 14 15 16

	Изход:
	68
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

int diagonalsSum(const int matrix[][MAX_SIZE], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += matrix[i][i];               // главен диагонал
		sum += matrix[i][size - 1 - i];    // второстепенен диагонал
	}

	// при нечетен размер централният елемент е на двата диагонала и е добавен два пъти
	if (size % 2 == 1)
	{
		sum -= matrix[size / 2][size / 2];
	}

	return sum;
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

	std::cout << diagonalsSum(matrix, size);
}
