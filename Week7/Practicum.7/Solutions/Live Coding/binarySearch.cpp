/*
	binarySearch:
	Да се напише функция, която в сортиран масив връща индекса на x или -1, ако x не се среща.

	Вход:
	7
	1 3 5 7 9 11 13
	9

	Изход:
	4
*/

#include <iostream>

int binarySearch(const int arr[], int size, int x)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == x)
		{
			return mid;
		}

		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
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

	std::cout << binarySearch(arr, size, x);
}
