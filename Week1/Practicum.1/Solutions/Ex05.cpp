/*
Задача 5: Да се напише програма, която приема главна латинска буква.
Да се изведе номерът ѝ в азбуката (A -> 1, B -> 2, ..., Z -> 26).

Вход: C, Изход: 3
*/

#include <iostream>

int main()
{
	char letter;
	std::cin >> letter;

	int position = letter - 'A' + 1;

	std::cout << position;
}