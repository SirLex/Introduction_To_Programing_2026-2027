/*
Задача 13: Въвеждат се две цели числа i и j (1 ≤ i ≤ j ≤ 9). Да се изведе таблицата за умножение на числата от i до
j
включително, във формата от примера.

Вход: 4 7
Изход:
| X |  4 |  5 |  6 |  7 |
| 4 | 16 | 20 | 24 | 28 |
| 5 | 20 | 25 | 30 | 35 |
| 6 | 24 | 30 | 36 | 42 |
| 7 | 28 | 35 | 42 | 49 |
*/

#include <iostream>

int main()
{
	int from, to;
	std::cin >> from >> to;

	std::cout << "| X |";
	for (int col = from; col <= to; col++)
	{
		std::cout << "  " << col << " |";
	}
	std::cout << '\n';

	for (int row = from; row <= to; row++)
	{
		std::cout << "| " << row << " |";

		for (int col = from; col <= to; col++)
		{
			int product = row * col;

			std::cout << (product < 10 ? "  " : " ") << product << " |";
		}

		std::cout << '\n';
	}
}
