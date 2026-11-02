/*
Задача 4: Въвежда се цяло число от 0 до 100. Да се изведе числото с думи на английски език.

Вход: 21, Изход: twenty one

Вход: 13, Изход: thirteen

Вход: 100, Изход: one hundred
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	if (number == 100)
	{
		std::cout << "one hundred";
	}
	else if (number >= 10 && number <= 19)
	{
		switch (number)
		{
		case 10: std::cout << "ten"; break;
		case 11: std::cout << "eleven"; break;
		case 12: std::cout << "twelve"; break;
		case 13: std::cout << "thirteen"; break;
		case 14: std::cout << "fourteen"; break;
		case 15: std::cout << "fifteen"; break;
		case 16: std::cout << "sixteen"; break;
		case 17: std::cout << "seventeen"; break;
		case 18: std::cout << "eighteen"; break;
		case 19: std::cout << "nineteen"; break;
		}
	}
	else
	{
		int tens = number / 10;
		int ones = number % 10;

		switch (tens)
		{
		case 2: std::cout << "twenty"; break;
		case 3: std::cout << "thirty"; break;
		case 4: std::cout << "forty"; break;
		case 5: std::cout << "fifty"; break;
		case 6: std::cout << "sixty"; break;
		case 7: std::cout << "seventy"; break;
		case 8: std::cout << "eighty"; break;
		case 9: std::cout << "ninety"; break;
		}

		if (tens != 0 && ones != 0)
		{
			std::cout << ' ';
		}

		if (ones != 0 || number == 0)
		{
			switch (ones)
			{
			case 0: std::cout << "zero"; break;
			case 1: std::cout << "one"; break;
			case 2: std::cout << "two"; break;
			case 3: std::cout << "three"; break;
			case 4: std::cout << "four"; break;
			case 5: std::cout << "five"; break;
			case 6: std::cout << "six"; break;
			case 7: std::cout << "seven"; break;
			case 8: std::cout << "eight"; break;
			case 9: std::cout << "nine"; break;
			}
		}
	}
}
