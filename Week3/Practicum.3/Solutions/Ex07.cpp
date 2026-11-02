/*
Задача 7: Въвежда се цяло положително число. Да се изведат цифрата, която образува най-дългата поредица от еднакви
последователни цифри в записа на числото, и дължината на тази поредица. Ако има няколко поредици с еднаква
максимална дължина, може да се изведе която и да е от тях. Използвайте long long, за да работи програмата и за
много големи числа.

Вход: 123555544, Изход: 5 4 times
*/

#include <iostream>

int main()
{
	long long number;
	std::cin >> number;

	int previousDigit = number % 10;
	number /= 10;

	int currentLength = 1;
	int bestDigit = previousDigit;
	int bestLength = 1;

	while (number > 0)
	{
		int digit = number % 10;

		// поредицата продължава, ако цифрата е като предишната, иначе започва нова
		currentLength = (digit == previousDigit) ? currentLength + 1 : 1;

		if (currentLength > bestLength)
		{
			bestLength = currentLength;
			bestDigit = digit;
		}

		previousDigit = digit;
		number /= 10;
	}

	std::cout << bestDigit << ' ' << bestLength << " times";
}
