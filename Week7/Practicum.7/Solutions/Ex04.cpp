/*
	Задача 4
	Въвежда се цяло число N и квадратна матрица от цели числа с размери N × N. Да се провери дали матрицата е
	симетрична спрямо главния си диагонал. Да се изведе true, ако е така, и false в противен случай.

	Вход:
	4
	0 2 3 4
	2 0 2 7
	3 2 0 9
	4 7 9 6

	Изход:
	true

	Вход:
	3
	3 2 5
	2 5 2
	7 2 3

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

bool isSymmetric(const int matrix[][MAX_SIZE], int size)
{
	// достатъчно е да сравним елементите над главния диагонал с огледалните им
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return false;
			}
		}
	}

	return true;
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

	std::cout << (isSymmetric(matrix, size) ? "true" : "false");
}
