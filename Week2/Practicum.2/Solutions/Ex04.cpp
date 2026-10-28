/*
Задача 4: Двама играчи играят на камък, ножица, хартия. Въвеждат се два символа - ходът на първия и ходът
на втория играч. Символът r или R означава камък, p или P - хартия, а s или S - ножица. Камъкът бие ножицата,
ножицата бие хартията, а хартията бие камъка. Да се изведе Player 1 wins, Player 2 wins или Draw.

Вход: r S, Изход: Player 1 wins

Вход: s r, Изход: Player 2 wins

Вход: P p, Изход: Draw
*/

#include <iostream>

int main()
{
	char first, second;
	std::cin >> first >> second;

	// превръщаме главните букви в малки, за да сравняваме само с r, p и s
	if (first >= 'A' && first <= 'Z')
	{
		first = first + ('a' - 'A');
	}
	if (second >= 'A' && second <= 'Z')
	{
		second = second + ('a' - 'A');
	}

	if (first == second)
	{
		std::cout << "Draw";
	}
	else if ((first == 'r' && second == 's')
		|| (first == 's' && second == 'p')
		|| (first == 'p' && second == 'r'))
	{
		std::cout << "Player 1 wins";
	}
	else
	{
		std::cout << "Player 2 wins";
	}
}
