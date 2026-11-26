/*
	Задача 9
	Дадена е матрица с размери NxM, 1 <= N, M <= 50. Напишете програма, която проверява дали всички диагонали
	от ляво на дясно (и нагоре) са нарастващи.

	Вход:
	3 4
	1 2 3 4
	5 6 7 8
	9 9 9 9

	Изход:
	false

	Вход:
	3 3
	9 8 7
	6 5 4
	3 2 1

	Изход:
	true
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

bool areDiagonalsIncreasing(const int matrix[][MAX_SIZE], int rows, int cols)
{
	// всеки елемент се сравнява със следващия по диагонала - този нагоре и надясно от него;
	// ако всички такива двойки са нарастващи, значи и всички диагонали са нарастващи
	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			if (matrix[i - 1][j + 1] <= matrix[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	if (rows < 1 || rows > 50 || cols < 1 || cols > 50)
	{
		return 1;
	}

	int matrix[MAX_SIZE][MAX_SIZE];
	readMatrix(matrix, rows, cols);

	std::cout << (areDiagonalsIncreasing(matrix, rows, cols) ? "true" : "false");
}
