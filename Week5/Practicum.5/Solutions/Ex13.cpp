/*
Задача 13: Напишете функция binarySearch, която приема сортиран във възходящ ред масив от цели числа, неговия
размер и число x и връща индекса на x в масива, като използва двоично търсене. Ако x не се среща в масива,
функцията да връща -1. Напишете програма, която въвежда сортиран масив и число x и извежда резултата от функцията.

Вход:
8
2 5 8 12 16 23 38 56
23

Изход:
5

Вход:
8
2 5 8 12 16 23 38 56
10

Изход:
-1
*/

#include <iostream>

// масивът се подава като const, защото функцията само чете от него
int binarySearch(const int arr[], int size, int x)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int middle = left + (right - left) / 2;

		if (arr[middle] == x)
		{
			return middle;
		}

		if (arr[middle] < x)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}

	return -1;
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

	int x;
	std::cin >> x;

	std::cout << binarySearch(arr, n, x);
}
