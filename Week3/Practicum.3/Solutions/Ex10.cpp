/*
Задача 10: Въвежда се цяло число n (1 ≤ n ≤ 9). Да се изведе квадрат с размер n × n, в който по главния диагонал са
числата от
1 до n, под диагонала - символът *, а над него - символът ..

Вход: 5
Изход:
1....
*2...
**3..
***4.
****5
*/

#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			if (row == col)
			{
				std::cout << row;
			}
			else if (row > col)
			{
				std::cout << '*';
			}
			else
			{
				std::cout << '.';
			}
		}
		std::cout << '\n';
	}
}
