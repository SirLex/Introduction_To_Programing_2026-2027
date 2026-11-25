/*
Семинар, задача 4: След масива се въвежда число x. Да се отпечатат индексът на първото и индексът на последното
срещане на x в масива, или -1, ако x не се среща.

Вход:
7
4 8 15 16 8 23 42
8

Изход:
First: 1
Last: 4

Вход:
3
1 2 3
7

Изход:
First: -1
Last: -1
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;

	int arr[MAX_SIZE];
	int n;
	std::cin >> n;

	if (n < 1 || n > MAX_SIZE)
	{
		std::cout << "Invalid size!\n";
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	int x;
	std::cin >> x;

	int first = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			first = i;
			break;
		}
	}

	// за последното срещане търсим отзад напред
	int last = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] == x)
		{
			last = i;
			break;
		}
	}

	std::cout << "First: " << first << '\n';
	std::cout << "Last: " << last << '\n';
}
