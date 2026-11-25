/*
Семинар, задача 6: Да се провери дали редицата a0, a1, ..., aN-1 е монотонно (нестрого) намаляваща, т.е. ai >= ai+1
за всяко i.

Вход:
10
1 2 3 4 5 6 7 8 9 10

Изход:
The sequence is not monotonically decreasing.

Вход:
5
5 4 3 1 0

Изход:
The sequence is monotonically decreasing.
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

	bool isDecreasing = true;

	// i стига до n - 2, защото сравняваме arr[i] с arr[i + 1]
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			isDecreasing = false;
			break;
		}
	}

	if (isDecreasing)
	{
		std::cout << "The sequence is monotonically decreasing.\n";
	}
	else
	{
		std::cout << "The sequence is not monotonically decreasing.\n";
	}
}
