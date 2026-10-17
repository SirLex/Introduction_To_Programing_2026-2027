/*
Задача 4: Въвежда се главна латинска буква. Да се изведе съответната ѝ малка буква.

Вход: G, Изход: g
*/

#include <iostream>

int main()
{
	char upper;
	std::cin >> upper;

	char lower = upper + ('a' - 'A');

	std::cout << lower;
}