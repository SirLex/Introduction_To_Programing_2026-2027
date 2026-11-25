/*
Семинар, задача 17: Въвеждат се N числа, всяко в интервала [0, 19]. Да се отпечата за всяко число, което се среща
поне веднъж, колко пъти се среща (в нарастващ ред на числата).

Вход:
8
3 1 3 0 19 1 3 5

Изход:
0: 1
1: 2
3: 3
5: 1
19: 1
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;
	const int VALUES_COUNT = 20;

	int n;
	std::cin >> n;

	if (n < 1 || n > MAX_SIZE)
	{
		std::cout << "Invalid size!\n";
		return 1;
	}

	// count[v] е колко пъти се среща числото v - самото число е индекс
	int count[VALUES_COUNT] = {};

	for (int i = 0; i < n; i++)
	{
		int number;
		std::cin >> number;
		count[number]++;
	}

	for (int value = 0; value < VALUES_COUNT; value++)
	{
		if (count[value] > 0)
		{
			std::cout << value << ": " << count[value] << '\n';
		}
	}
}
