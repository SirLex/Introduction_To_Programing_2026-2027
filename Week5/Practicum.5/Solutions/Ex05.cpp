/*
Задача 5: Въвежда се масив от неотрицателни цели числа с най-много 10 елемента (индекси от 0 до 9). Да се занулят
всички елементи, които не съдържат като цифра индекса, на който се намират, и да се изведе масивът. Например
числото 123 на индекс 4 се занулява, защото не съдържа цифрата 4.

Вход:
7
45 62 23 47 47 65 100

Изход:
0 0 23 0 47 65 0
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 10;

	int arr[MAX_SIZE];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		bool containsIndex = false;
		int number = arr[i];

		// do-while, за да се провери и числото 0 (то съдържа цифрата 0)
		do
		{
			if (number % 10 == i)
			{
				containsIndex = true;
			}
			number /= 10;
		} while (number > 0);

		if (!containsIndex)
		{
			arr[i] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
		if (i < n - 1)
		{
			std::cout << ' ';
		}
	}
}
