/*
Задача 3: Въвеждат се две цели числа - номер на месец (от 1 до 12) и година. Да се изведе броят на дните в този
месец, като
се вземе предвид дали годината е високосна.

Вход: 2 2024, Изход: 29

Вход: 2 1900, Изход: 28

Вход: 4 2025, Изход: 30
*/

#include <iostream>

int main()
{
	int month, year;
	std::cin >> month >> year;

	bool isLeap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

	int days = 0;

	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	case 2:
		days = isLeap ? 29 : 28;
		break;
	default:
		days = 31;
		break;
	}

	std::cout << days;
}
