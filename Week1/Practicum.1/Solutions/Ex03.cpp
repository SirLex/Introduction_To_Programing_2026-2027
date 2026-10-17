/*
Задача 3: Да се напише програма, която приема символ. Да се изведе ASCII кодът му.

Вход: A, Изход: 65
*/

#include <iostream>

int main()
{
	char symbol;
	std::cin >> symbol;

	int asciiCode = symbol;

	std::cout << asciiCode;

	return 0;
}