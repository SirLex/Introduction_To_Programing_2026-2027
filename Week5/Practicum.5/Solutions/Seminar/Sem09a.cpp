/*
Семинар, задача 9а: Да се обърне масивът на място (без втори масив) и да се отпечата.

Вход:
7
1 2 3 4 5 6 7

Изход:
7 6 5 4 3 2 1
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

	// разменяме първия с последния, втория с предпоследния и т.н. до средата
	for (int i = 0; i < n / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}

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
