/*
	Задача 4
	Въвежда се матрица, в която всеки ред е сортиран във възходящ ред, а първият елемент на всеки ред
	е по-голям от последния елемент на предходния ред. След матрицата се въвежда цяло число X.
	Да се провери дали X се среща в матрицата.

	Вход:
	3 4
	1 3 5 7
	10 11 16 20
	23 30 34 60
	3

	Изход:
	true

	Вход:
	3 4
	1 3 5 7
	10 11 16 20
	23 30 34 60
	13

	Изход:
	false
*/

#include <iostream>

const int MAX_SIZE = 100;

int findRow(const int matrix[][MAX_SIZE], int rows, int cols, int x)
{
	int left = 0;
	int right = rows - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (x < matrix[mid][0])
		{
			right = mid - 1;
		}
		else if (x > matrix[mid][cols - 1])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

int binarySearch(const int arr[], int size, int x)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == x)
		{
			return mid;
		}

		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

bool searchMatrix(const int matrix[][MAX_SIZE], int rows, int cols, int x)
{
	int row = findRow(matrix, rows, cols, x);
	if (row == -1)
	{
		return false;
	}

	return binarySearch(matrix[row], cols, x) != -1;
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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	int x;
	std::cin >> x;

	std::cout << (searchMatrix(matrix, rows, cols, x) ? "true" : "false");
}
