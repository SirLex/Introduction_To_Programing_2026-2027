/*
	Задача 1: indexOf
	Да се напише функция, която връща индекса на първото срещане на x в масива или -1, ако x не се среща.

	Вход:
	5
	4 7 1 7 3
	7

	Изход:
	1
*/

#include <iostream>

int indexOf(const int arr[], int size, int x)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	const int MAX_SIZE = 100;

	int size;
	std::cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		return 1;
	}

	int arr[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int x;
	std::cin >> x;

	std::cout << indexOf(arr, size, x);
}
