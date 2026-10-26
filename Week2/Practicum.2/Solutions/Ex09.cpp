/*
Задача 9: Въвежда се неотрицателно цяло число. Да се изведе числото, записано с цифрите в обратен ред.

Вход: 1234, Изход: 4321

Вход: 120, Изход: 21
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	int reversed = 0;

	while (number > 0)
	{
		int lastDigit = number % 10;
		reversed = reversed * 10 + lastDigit;
		number /= 10;
	}

	std::cout << reversed;
}
