/*
Задача 3: Въвежда се цяло положително число. Да се изведе денят от седмицата според остатъка на числото
при делене на 7: остатък 0 - Monday, остатък 1 - Tuesday, и т.н. до остатък 6 - Sunday.

Вход: 14, Изход: Monday

Вход: 10, Изход: Thursday
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	int remainder = number % 7;

	if (remainder == 0)
	{
		std::cout << "Monday";
	}
	else if (remainder == 1)
	{
		std::cout << "Tuesday";
	}
	else if (remainder == 2)
	{
		std::cout << "Wednesday";
	}
	else if (remainder == 3)
	{
		std::cout << "Thursday";
	}
	else if (remainder == 4)
	{
		std::cout << "Friday";
	}
	else if (remainder == 5)
	{
		std::cout << "Saturday";
	}
	else
	{
		std::cout << "Sunday";
	}
}
