/*
Задача 8: Въвежда се неотрицателно цяло число. Да се изведе колко цифри има то.

Вход: 12345, Изход: 5

Вход: 0, Изход: 1
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	// започваме от 1, защото всяко число има поне една цифра
	int digitsCount = 1;

	while (number >= 10)
	{
		number /= 10;
		digitsCount++;
	}

	std::cout << digitsCount;
}
