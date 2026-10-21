/*
Задача 9: Въвежда се трицифрено число. Да се изведе 1, ако числото е палиндром
(чете се еднакво отляво надясно и отдясно наляво), и 0 в противен случай.

Вход: 121, Изход: 1

Вход: 731, Изход: 0
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	int firstDigit = number / 100;
	int lastDigit = number % 10;

	bool isPalindrome = (firstDigit == lastDigit);

	std::cout << isPalindrome;
}