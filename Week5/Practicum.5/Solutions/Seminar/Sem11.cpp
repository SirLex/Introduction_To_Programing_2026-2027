/*
Семинар, задача 11: След масива се въвежда индекс pos. Да се изтрие елементът на позиция pos (останалите се
изместват наляво) и да се отпечата новият масив. Ако индексът е невалиден, да се отпечата Invalid index!.

Вход:
8
33 1 23 8 54 5 1 6
4

Изход:
33 1 23 8 5 1 6
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

	int pos;
	std::cin >> pos;

	if (pos < 0 || pos >= n)
	{
		std::cout << "Invalid index!\n";
	}
	else
	{
		// всеки елемент след pos се премества с една позиция наляво
		for (int i = pos; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		n--;

		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i];
			if (i < n - 1)
			{
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}
}
