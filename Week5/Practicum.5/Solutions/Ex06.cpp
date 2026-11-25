/*
Задача 6: След масива се въвежда число k (1 <= k <= N). Да се изведат всички подмасиви с дължина k, т.е. всички
поредици от k последователни елементи, всеки на отделен ред.

Вход:
6
1 2 3 4 5 6
3

Изход:
1 2 3
2 3 4
3 4 5
4 5 6
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

	int k;
	std::cin >> k;

	// последният подмасив започва на индекс n - k
	for (int start = 0; start <= n - k; start++)
	{
		for (int i = start; i < start + k; i++)
		{
			std::cout << arr[i];
			if (i < start + k - 1)
			{
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}
}
