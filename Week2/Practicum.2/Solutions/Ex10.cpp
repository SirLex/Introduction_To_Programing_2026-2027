/*
Задача 10: Въвежда се неотрицателно цяло число. Да се изведе Palindrome, ако числото се чете еднакво отляво надясно
и отдясно наляво, и Not a palindrome в противен случай.

Вход: 12321, Изход: Palindrome

Вход: 1230, Изход: Not a palindrome
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	int original = number;
	int reversed = 0;

	while (number > 0)
	{
		reversed = reversed * 10 + number % 10;
		number /= 10;
	}

	if (original == reversed)
	{
		std::cout << "Palindrome";
	}
	else
	{
		std::cout << "Not a palindrome";
	}
}
