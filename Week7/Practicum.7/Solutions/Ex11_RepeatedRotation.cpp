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

// завърта матрицата на 90 градуса по часовниковата стрелка;
// след завъртането редовете и колоните си разменят броя
void rotateClockwise(int matrix[][MAX_SIZE], int& rows, int& cols)
{
	int rotated[MAX_SIZE][MAX_SIZE];

	// елементът от ред i отива в колона rows - 1 - i, а колоната j става ред j
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			rotated[j][rows - 1 - i] = matrix[i][j];
		}
	}

	int temp = rows;
	rows = cols;
	cols = temp;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rotated[i][j];
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

	int deg;
	std::cin >> deg;

	if (deg % 90 != 0)
	{
		return 1;
	}

	// завъртане обратно на часовниковата стрелка на 90 е същото като три завъртания по нея;
	// затова броят завъртания се привежда в интервала [0; 3]
	int turns = (deg / 90) % 4;
	if (turns < 0)
	{
		turns += 4;
	}

	for (int t = 0; t < turns; t++)
	{
		rotateClockwise(matrix, rows, cols);
	}

	printMatrix(matrix, rows, cols);
}
