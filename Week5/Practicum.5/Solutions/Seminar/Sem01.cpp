/*
Семинар, задача 1: Да се въведат N числа в масив и да се отпечатат: 1. в обратен ред; 2. само елементите на четни
индекси (0, 2, 4, ...).

Вход:
5
1 2 3 4 5

Изход:
5 4 3 2 1
1 3 5
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

	for (int i = n - 1; i >= 0; i--)
	{
		std::cout << arr[i];
		if (i > 0)
		{
			std::cout << ' ';
		}
	}
	std::cout << '\n';

	for (int i = 0; i < n; i += 2)
	{
		std::cout << arr[i];
		if (i + 2 < n)
		{
			std::cout << ' ';
		}
	}
	std::cout << '\n';
}
