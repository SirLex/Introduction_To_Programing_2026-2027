/*
Задача 14: Разширете играта от задача 4, така че да се играе до определен брой точки.

Първо се въвежда цяло число maxScore. Ако то не е положително, да се изведе Invalid max score и да се въведе отново,
докато не бъде въведена валидна стойност.

След това играчите играят рунд след рунд, като във всеки рунд се въвеждат ходовете на двамата играчи. Ако някой
от ходовете не е валиден символ, да се изведе Invalid move и рундът да се изиграе отново. Победителят в рунда получава
точка, а при равенство никой не получава точка. След всеки валиден рунд да се изведе текущият резултат във формат
Score: X - Y.

Когато някой от играчите достигне maxScore точки, да се изведе Player 1 wins the game! или Player 2 wins the game!
и програмата да приключи.

Вход:          Изход:
0              Invalid max score
2
r s            Score: 1 - 0
p p            Score: 1 - 0
x r            Invalid move
s p            Score: 2 - 0
               Player 1 wins the game!
*/

#include <iostream>

int main()
{
	int maxScore;
	std::cin >> maxScore;

	while (maxScore <= 0)
	{
		std::cout << "Invalid max score\n";
		std::cin >> maxScore;
	}

	int firstScore = 0;
	int secondScore = 0;

	while (firstScore < maxScore && secondScore < maxScore)
	{
		char first, second;
		std::cin >> first >> second;

		if (first >= 'A' && first <= 'Z')
		{
			first = first + ('a' - 'A');
		}
		if (second >= 'A' && second <= 'Z')
		{
			second = second + ('a' - 'A');
		}

		bool isFirstValid = (first == 'r' || first == 'p' || first == 's');
		bool isSecondValid = (second == 'r' || second == 'p' || second == 's');

		if (!isFirstValid || !isSecondValid)
		{
			std::cout << "Invalid move\n";
		}
		else
		{
			if ((first == 'r' && second == 's')
				|| (first == 's' && second == 'p')
				|| (first == 'p' && second == 'r'))
			{
				firstScore++;
			}
			else if (first != second)
			{
				secondScore++;
			}

			std::cout << "Score: " << firstScore << " - " << secondScore << '\n';
		}
	}

	if (firstScore == maxScore)
	{
		std::cout << "Player 1 wins the game!\n";
	}
	else
	{
		std::cout << "Player 2 wins the game!\n";
	}
}
