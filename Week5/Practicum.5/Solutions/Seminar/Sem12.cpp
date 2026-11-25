/*
Семинар, задача 12: След масива се въвеждат позиция pos (0 <= pos <= N) и стойност value. Да се вмъкне value на
позиция pos и да се отпечата новият масив. Ако масивът е пълен (N = 100), да се отпечата Array is full!, а при
невалидна позиция - Invalid position!.

Вход:
5
10 20 30 40 50
2 25

Изход:
10 20 25 30 40 50

Вход:
3
1 2 3
3 4

Изход:
1 2 3 4
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

	int pos, value;
	std::cin >> pos >> value;

	if (n == MAX_SIZE)
	{
		std::cout << "Array is full!\n";
	}
	else if (pos < 0 || pos > n)
	{
		std::cout << "Invalid position!\n";
	}
	else
	{
		// местим надясно, като обхождаме отдясно наляво,
		// иначе ще презапишем още непреместени стойности
		for (int i = n; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[pos] = value;
		n++;

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
