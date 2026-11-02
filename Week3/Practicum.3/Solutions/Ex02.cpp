/*
Задача 2: Въвежда се цяло число от 1 до 12 - номер на месец. Да се изведе сезонът, към който принадлежи месецът:
Winter - декември (12), януари (1), февруари (2)
Spring - март (3), април (4), май (5)
Summer - юни (6), юли (7), август (8)
Autumn - септември (9), октомври (10), ноември (11)

Вход: 1, Изход: Winter

Вход: 10, Изход: Autumn
*/

#include <iostream>

int main()
{
	int month;
	std::cin >> month;

	// няколко case-а без break помежду им водят до един и същ клон
	switch (month)
	{
	case 12:
	case 1:
	case 2:
		std::cout << "Winter";
		break;
	case 3:
	case 4:
	case 5:
		std::cout << "Spring";
		break;
	case 6:
	case 7:
	case 8:
		std::cout << "Summer";
		break;
	case 9:
	case 10:
	case 11:
		std::cout << "Autumn";
		break;
	}
}
