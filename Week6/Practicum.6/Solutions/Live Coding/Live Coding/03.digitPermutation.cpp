/*
	Задача 3: Пермутация на цифри
	Въвежда се число N и след това два масива с по N елемента, като всички елементи са цифри от 0 до 9.
	Да се изведе Yes, ако вторият масив е пермутация на първия (съдържа същите цифри, същия брой пъти,
	в произволен ред), и No в противен случай.

	Вход:
	5
	1 2 3 2 9
	2 9 1 2 3

	Изход:
	Yes

	Вход:
	3
	1 1 2
	1 2 2

	Изход:
	No
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;
	const int DIGITS_COUNT = 10;

	int size;
	std::cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		return 1;
	}

	int first[MAX_SIZE];
	int second[MAX_SIZE];

	for (int i = 0; i < size; i++)
	{
		std::cin >> first[i];
	}
	for (int i = 0; i < size; i++)
	{
		std::cin >> second[i];
	}

	// counter[d] показва колко пъти повече се среща цифрата d в първия масив, отколкото във втория
	int counter[DIGITS_COUNT] = {};

	for (int i = 0; i < size; i++)
	{
		counter[first[i]]++;
		counter[second[i]]--;
	}

	bool isPermutation = true;
	for (int d = 0; d < DIGITS_COUNT && isPermutation; d++)
	{
		if (counter[d] != 0)
		{
			isPermutation = false;
		}
	}

	std::cout << (isPermutation ? "Yes" : "No");
}
