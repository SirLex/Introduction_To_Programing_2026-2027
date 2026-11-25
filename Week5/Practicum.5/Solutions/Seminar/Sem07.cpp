/*
Семинар, задача 7: Да се провери дали всички елементи на редицата са различни.

Вход:
5
1 2 3 4 5

Изход:
Yes, the sequence consists of distinct elements.

Вход:
5
1 2 3 4 2

Изход:
No, the sequence does not consist of distinct elements.
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

	bool areDistinct = true;

	// всеки елемент се сравнява само с елементите след него
	for (int i = 0; i < n - 1 && areDistinct; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				areDistinct = false;
				break;
			}
		}
	}

	if (areDistinct)
	{
		std::cout << "Yes, the sequence consists of distinct elements.\n";
	}
	else
	{
		std::cout << "No, the sequence does not consist of distinct elements.\n";
	}
}
