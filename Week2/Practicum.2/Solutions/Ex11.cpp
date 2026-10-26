/*
Задача 11: Въвежда се естествено число n, а след него - n цели числа. Да се изведе средноаритметичното им.

Вход: 4
      2 5 6 3, Изход: 4

Вход: 3
      1 2 2,   Изход: 1.66667
*/

#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int number;
		std::cin >> number;
		sum += number;
	}

	double average = (double)sum / n;

	std::cout << average;
}
