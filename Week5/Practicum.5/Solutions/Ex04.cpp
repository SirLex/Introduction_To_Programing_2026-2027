/*
Задача 4: Въвеждат се два масива - първо N и N числа, след това M и M числа. Да се попълни трети масив, в който
всеки елемент е произведението на елементите на двата масива на същата позиция. Ако масивите са с различна дължина,
позициите, които съществуват само в по-дългия масив, се попълват с елементите му без промяна. Да се изведе третият
масив.

Вход:
8
2 4 2 3 6 5 4 7
5
8 6 9 1 0

Изход:
16 24 18 3 0 5 4 7
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;

	int first[MAX_SIZE];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> first[i];
	}

	int second[MAX_SIZE];
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> second[i];
	}

	int result[MAX_SIZE];
	int resultSize = (n > m) ? n : m;

	for (int i = 0; i < resultSize; i++)
	{
		if (i < n && i < m)
		{
			result[i] = first[i] * second[i];
		}
		else if (i < n)
		{
			result[i] = first[i];
		}
		else
		{
			result[i] = second[i];
		}
	}

	for (int i = 0; i < resultSize; i++)
	{
		std::cout << result[i];
		if (i < resultSize - 1)
		{
			std::cout << ' ';
		}
	}
}
