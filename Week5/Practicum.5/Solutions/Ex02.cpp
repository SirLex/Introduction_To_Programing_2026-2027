/*
Задача 2: Фиксиран елемент на масив наричаме елемент, чиято стойност е равна на индекса му. Да се изведе броят на
фиксираните елементи в масива.

Вход:
9
0 5 7 8 4 1 5 70 -9

Изход:
2
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;

	int arr[MAX_SIZE];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	int fixedCount = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == i)
		{
			fixedCount++;
		}
	}

	std::cout << fixedCount;
}
