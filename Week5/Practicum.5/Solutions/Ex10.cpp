/*
Задача 10: Въвежда се число N и след това два масива с по N елемента, като всички елементи са цифри от 0 до 9. Да
се изведе Yes, ако вторият масив е пермутация на първия (съдържа същите цифри, същия брой пъти, в произволен ред),
и No в противен случай.

Вход:
6
0 7 6 3 9 1
0 1 3 6 7 9

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
	const int DIGITS_COUNT = 10;

	int n;
	std::cin >> n;

	// не е нужно да пазим самите масиви - достатъчно е да преброим цифрите
	int firstCount[DIGITS_COUNT] = {};
	int secondCount[DIGITS_COUNT] = {};

	for (int i = 0; i < n; i++)
	{
		int digit;
		std::cin >> digit;
		firstCount[digit]++;
	}

	for (int i = 0; i < n; i++)
	{
		int digit;
		std::cin >> digit;
		secondCount[digit]++;
	}

	bool isPermutation = true;

	for (int digit = 0; digit < DIGITS_COUNT; digit++)
	{
		if (firstCount[digit] != secondCount[digit])
		{
			isPermutation = false;
			break;
		}
	}

	if (isPermutation)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
}
