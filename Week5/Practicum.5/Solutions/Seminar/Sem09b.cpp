/*
Семинар, задача 9б: След масива се въвежда число K (0 <= K <= N). Да се обърнат само първите K елемента.

Вход:
7
1 2 3 4 5 6 7
4

Изход:
4 3 2 1 5 6 7
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

	int k;
	std::cin >> k;

	if (k < 0 || k > n)
	{
		std::cout << "Invalid K!\n";
		return 1;
	}

	// същото като обръщането на целия масив, но само за първите k елемента
	for (int i = 0; i < k / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[k - 1 - i];
		arr[k - 1 - i] = temp;
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
