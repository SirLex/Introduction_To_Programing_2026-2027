/*
Задача 7: Въвеждат се цели числа n и k, като k >= 0. Да се изведе n на степен k. Ако n и k са едновременно 0,
да се изведе Undefined. Приемете, че резултатът се побира в long long.

Вход: 2 10, Изход: 1024

Вход: -3 3, Изход: -27

Вход: 0 0, Изход: Undefined
*/

#include <iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	if (n == 0 && k == 0)
	{
		std::cout << "Undefined";
	}
	else
	{
		long long result = 1;

		for (int i = 0; i < k; i++)
		{
			result *= n;
		}

		std::cout << result;
	}
}
