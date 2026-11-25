/*
Семинар, задача 3: Да се намерят най-малкият и най-големият елемент, както и индексът на първото им срещане.

Вход:
9
3 1 2 8 13 5 1 6 25

Изход:
Min: 1 (index 1)
Max: 25 (index 8)
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

	// започваме от първия елемент, а не от 0 - масивът може да има само отрицателни числа
	int minIndex = 0;
	int maxIndex = 0;

	for (int i = 1; i < n; i++)
	{
		// строги сравнения, за да остане индексът на първото срещане
		if (arr[i] < arr[minIndex])
		{
			minIndex = i;
		}
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}

	std::cout << "Min: " << arr[minIndex] << " (index " << minIndex << ")\n";
	std::cout << "Max: " << arr[maxIndex] << " (index " << maxIndex << ")\n";
}
