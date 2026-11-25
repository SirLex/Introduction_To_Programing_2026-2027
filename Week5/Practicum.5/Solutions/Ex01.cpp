/*
Задача 1: Въвежда се масив от N реални числа. Да се изведат сборът на положителните елементи и броят на
отрицателните елементи.

Вход:
6
2.5 -1 3 -4.2 0 1.5

Изход:
Sum of positive: 7
Negative: 2
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;
	const double EPS = 1e-9;

	double arr[MAX_SIZE];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	double positiveSum = 0;
	int negativeCount = 0;

	for (int i = 0; i < n; i++)
	{
		// числата между -EPS и EPS се смятат за 0 и не са нито положителни, нито отрицателни
		if (arr[i] > EPS)
		{
			positiveSum += arr[i];
		}
		else if (arr[i] < -EPS)
		{
			negativeCount++;
		}
	}

	std::cout << "Sum of positive: " << positiveSum << '\n';
	std::cout << "Negative: " << negativeCount << '\n';
}
