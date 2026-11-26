/*
	Задача 5
	Въвеждат се цели числа N и M, матрица от цели числа с размери N × M и цяло число K (1 ≤ K ≤ M). Да се
	изведат елементите на матрицата във формата на стълбище. Всяко стъпало се извежда на отделен ред и се
	състои от K последователни елемента от един ред на матрицата. Първото стъпало започва от първата колона
	на първия ред, а всяко следващо е от следващия ред и започва от колоната веднага след последната колона
	на предходното стъпало. Ако в реда са останали по-малко от K елемента, стъпалото се състои само от тях.
	Когато стъпало стигне до последната колона, следващото започва отново от първата колона.

	Вход:
	5 5
	1 2 3 4 5
	6 7 8 9 10
	11 12 13 14 15
	16 17 18 19 20
	21 22 23 24 25
	2

	Изход:
	1 2
	8 9
	15
	16 17
	23 24

	Обяснение:
	[ 1   2]  3   4   5
	  6   7 [ 8   9] 10
	 11  12  13  14 [15]
	[16  17] 18  19  20
	 21  22 [23  24] 25
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

void printStaircase(const int matrix[][MAX_SIZE], int rows, int cols, int k)
{
	int start = 0;

	for (int i = 0; i < rows; i++)
	{
		int end = start + k;
		if (end > cols)
		{
			end = cols;
		}

		for (int j = start; j < end; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';

		// ако стъпалото е стигнало последната колона, стълбището започва отначало
		start = (end == cols) ? 0 : end;
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

	int k;
	std::cin >> k;

	if (k < 1 || k > cols)
	{
		return 1;
	}

	printStaircase(matrix, rows, cols, k);
}
