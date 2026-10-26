/*
Задача 1: Въвежда се цяло число. Да се изведе Even, ако числото е четно, и Odd, ако е нечетно.

Вход: 7, Изход: Odd

Вход: -4, Изход: Even
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	if (number % 2 == 0)
	{
		std::cout << "Even";
	}
	else
	{
		std::cout << "Odd";
	}
}
