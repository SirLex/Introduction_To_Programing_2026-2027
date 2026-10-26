/*
Задача 12: Въвежда се естествено число. Да се изведе Prime, ако числото е просто, и Not prime в противен случай.

Вход: 17, Изход: Prime

Вход: 1, Изход: Not prime

Вход: 21, Изход: Not prime
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	// 1 не е просто число
	bool isPrime = (number >= 2);

	// достатъчно е да проверим делителите до корен квадратен от числото;
	// цикълът спира и щом намерим делител
	for (int divisor = 2; divisor * divisor <= number && isPrime; divisor++)
	{
		if (number % divisor == 0)
		{
			isPrime = false;
		}
	}

	if (isPrime)
	{
		std::cout << "Prime";
	}
	else
	{
		std::cout << "Not prime";
	}
}
