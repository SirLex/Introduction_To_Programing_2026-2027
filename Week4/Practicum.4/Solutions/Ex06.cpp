/*
Задача 6: Напишете функция reverseNumber(unsigned int n), която връща числото, записано с цифрите в обратен ред.

reverseNumber(1234)  ->  4321
reverseNumber(1200)  ->  21
*/

#include <iostream>

unsigned int reverseNumber(unsigned int n)
{
	unsigned int reversed = 0;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	return reversed;
}

int main()
{
	unsigned int n;
	std::cin >> n;

	std::cout << reverseNumber(n);
}
