/*
Задача 5: Правилният ПИН код е 1234 и е зададен в програмата като константа. Потребителят има най-много три опита
да го
въведе. След всеки грешен опит да се изведе Wrong PIN. Ако ПИН кодът е въведен правилно, да се изведе Access
granted и програмата да приключи. Ако и трите опита са грешни, да се изведе Card blocked.

Вход:  Изход:
1111   Wrong PIN
1234   Access granted

Вход:  Изход:
1111   Wrong PIN
2222   Wrong PIN
3333   Wrong PIN
       Card blocked
*/

#include <iostream>

int main()
{
	const int CORRECT_PIN = 1234;
	const int MAX_ATTEMPTS = 3;

	bool isGranted = false;

	for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
	{
		int pin;
		std::cin >> pin;

		if (pin == CORRECT_PIN)
		{
			isGranted = true;
			break;
		}

		std::cout << "Wrong PIN\n";
	}

	// след цикъла проверяваме дали е спрял заради break или защото опитите са свършили
	if (isGranted)
	{
		std::cout << "Access granted\n";
	}
	else
	{
		std::cout << "Card blocked\n";
	}
}
