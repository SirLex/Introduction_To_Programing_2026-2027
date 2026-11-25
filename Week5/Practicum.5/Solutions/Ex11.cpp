/*
Задача 11: Напишете функция haveSameSet, която приема два масива от цели числа и размерите им и връща дали двата
масива са образувани от едно и също множество от числа, т.е. всеки елемент на първия масив се среща във втория и
всеки елемент на втория масив се среща в първия, без значение от реда и от повторенията. Напишете програма, която
въвежда двата масива - първо N и N числа, след това M и M числа - и извежда Yes или No според резултата от
функцията.

Вход:
4
1 2 2 3
3
3 1 2

Изход:
Yes

Вход:
3
1 2 3
3
1 2 4

Изход:
No
*/

#include <iostream>

bool contains(const int arr[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}

	return false;
}

// дали всеки елемент на subset се среща в superset
bool isSubset(const int subset[], int subsetSize, const int superset[], int supersetSize)
{
	for (int i = 0; i < subsetSize; i++)
	{
		if (!contains(superset, supersetSize, subset[i]))
		{
			return false;
		}
	}

	return true;
}

bool haveSameSet(const int first[], int firstSize, const int second[], int secondSize)
{
	// една и съща функция, извикана с разменени аргументи
	return (isSubset(first, firstSize, second, secondSize)
		&& isSubset(second, secondSize, first, firstSize));
}

int main()
{
	const int MAX_SIZE = 100;

	int first[MAX_SIZE];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> first[i];
	}

	int second[MAX_SIZE];
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> second[i];
	}

	if (haveSameSet(first, n, second, m))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
}
