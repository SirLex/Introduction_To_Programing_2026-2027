/*
Задача 3: Напишете функция countOccurrences, която приема масив от цели числа, размера му и число x и връща колко
пъти x се среща в масива. Използвайте я, за да изведете всички елементи на въведения масив, които се срещат в него
точно веднъж, в реда, в който се срещат. Ако няма такива елементи, да се изведе None.

Вход:
10
2 1 5 7 3 2 3 5 2 4

Изход:
1 7 4
*/

#include <iostream>

int countOccurrences(const int arr[], int size, int x)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
	}

	return count;
}

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

	bool hasUnique = false;

	for (int i = 0; i < n; i++)
	{
		if (countOccurrences(arr, n, arr[i]) == 1)
		{
			if (hasUnique)
			{
				std::cout << ' ';
			}
			std::cout << arr[i];
			hasUnique = true;
		}
	}

	if (!hasUnique)
	{
		std::cout << "None";
	}
}
